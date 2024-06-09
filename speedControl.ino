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
  // Boucle_Variation.Pwm_Min + (max((1 / (1 + (exp(LAMBDA * Boucle_Variation.X)))) * Boucle_Variation.Pwm_Delta, 0));
  delay(TIME_STEP * 1000);
  speedParameters.i++;
  if (speedParameters.i >= speedParameters.nPoint)
  {
    currentPwm = targetPwm;
  }
}
/*
int deceleration(float Temps_Accel, float LAMBDA, float Consigne_Mem, float Consigne, struct Bouclage &Boucle_Variation)
{
  if (Boucle_Variation.Init == 0)
  {
    init_struct(Temps_Accel, LAMBDA, Consigne_Mem, Consigne, -1);
  }
  if (Boucle_Variation.Init == 1)
  {
    Serial.println("---Calcul---");
    Boucle_Variation.TempsPoint = (Temps_Accel / Boucle_Variation.NbPoint) + Boucle_Variation.TempsPoint;
    Boucle_Variation.X = (1.0 / Boucle_Variation.NbPoint) + Boucle_Variation.X;
    if (Consigne == 0)
    {
      Boucle_Variation.Pwm = max((1 / (1 + (exp(LAMBDA * Boucle_Variation.X)))) * Boucle_Variation.Pwm_Start, 0);
    }
    else
    {
      Boucle_Variation.Pwm = Boucle_Variation.Pwm_Min + (max((1 / (1 + (exp(LAMBDA * Boucle_Variation.X)))) * Boucle_Variation.Pwm_Delta, 0));
    }
    delay(Boucle_Variation.IntervalTemps * 1000);
    Serial.print(" | TempsPoint =");
    Serial.print(Boucle_Variation.TempsPoint);
    Serial.print(" | X =");
    Serial.print(Boucle_Variation.X);
    Serial.print(" | PWM = ");
    Serial.print(Boucle_Variation.Pwm);
    Serial.println();
    Boucle_Variation.i++;

    Serial.println("---Fin de calcul---");
  }
  if (Boucle_Variation.i >= Boucle_Variation.NbPoint)
  {
    Consigne_Mem = Consigne;
    Boucle_Variation.Init = 0;
    Serial.println("---Fin d'accélération---");
  }
  return Consigne_Mem;
}*/
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
