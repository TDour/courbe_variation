#include "read_consigne.h"
#include "utils.h"
// #ifndef  PARAMETERS_H
// #include "parameters.h"
// #endif
#include "speed_Control.h"

void setup()
{
  Serial.begin(9600);
  Serial.println("---------");
  Serial.println(" INIT OK ");
  Serial.println("---------");
}

struct dataStruct speedParameters;

void loop()
{
  int targetPwm;
  int currentPwm;

  if (readConsigne(targetPwm))
  {
    reset(currentPwm, targetPwm, speedParameters);
  }

  if (currentPwm < targetPwm)
  {
        Serial.print(currentPwm);

    speedUp(currentPwm, targetPwm, speedParameters);
  }

  else if (currentPwm > targetPwm)
  {
    slowDown(currentPwm, targetPwm, speedParameters);
  }
  delay(1000);
  printStatus(targetPwm, currentPwm);
}
