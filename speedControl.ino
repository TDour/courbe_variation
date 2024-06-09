#include <stdlib.h>
#include <math.h>
#include "read_Consigne.h"
// #ifndef  PARAMETERS_h
// #include "parameters.h"
// #endif
// #include "parameters.h"
// #include <Arduino.h>

void speedUp(int &currentPwm, int targetPwm, struct dataStruct &speedParameters)
{
  speedParameters.pointTime = (VARIATION_TIME / speedParameters.nPoint) + speedParameters.pointTime;
  speedParameters.X = (1.0 / speedParameters.nPoint) + speedParameters.X;

  currentPwm = (max((1 / (1 + (exp(-LAMBDA * speedParameters.X)))) * speedParameters.deltaPwm, 0)) + speedParameters.pwmStart;
  delay(TIME_STEP * 1000);
  Serial.print("i = ");
  Serial.println(speedParameters.i);
  speedParameters.i++;
  if (speedParameters.i >= speedParameters.nPoint)
  {
    currentPwm = targetPwm;
  }
}

void slowDown(int &currentPwm, int targetPwm, struct dataStruct &speedParameters)
{
  speedParameters.pointTime = (VARIATION_TIME / speedParameters.nPoint) + speedParameters.pointTime;
  speedParameters.X = (1.0 / speedParameters.nPoint) + speedParameters.X;

  currentPwm = targetPwm + (max((1 / (1 + (exp(LAMBDA * speedParameters.X)))) * speedParameters.deltaPwm, 0)); // speedParameters.pwmStart;
  
  delay(TIME_STEP * 1000);
  speedParameters.i++;
  if (speedParameters.i >= speedParameters.nPoint)
  {
    currentPwm = targetPwm;
    if (speedParameters.consigne == 0)
    {
      stop_motor(currentPwm);
      // ICI GERER LA FONCITON STOP MOTOR qui force le curent_pwm à 0
    }
  }
}

void stop_motor(int &currentpwm)
{
  currentpwm = 0
}

void reset(int &currentPwm, int targetPwm, struct dataStruct &speedParameters)
{
  speedParameters.deltaPwm = abs(currentPwm - targetPwm);
  speedParameters.pointTime = 0.0;
  speedParameters.pwmStart = currentPwm;
  speedParameters.X = -0.5;
  speedParameters.i = 0;
  // speedParameters.nPoint =int( ((abs(targetPwm-currentPwm) *100)/(191-63) * 20 * VARIATION_TIME ));
  // Serial.print("nPoint0 = ");
  speedParameters.nPoint = int(((float(speedParameters.deltaPwm) / 255.0) * VARIATION_TIME) / TIME_STEP);
  // Serial.println((abs(targetPwm-currentPwm) *100)/(191-63));
  // int(20 * VARIATION_TIME * float(convertPwmToPercent(targetPwm)) / 100);
  /////////////////////////////////////

  /////////////////////////////////////
  Serial.println();
  Serial.print(">>>deltaPwm = ");
  Serial.println(speedParameters.deltaPwm);
  Serial.print(">>>nPoint = ");
  Serial.println(speedParameters.nPoint);
}
