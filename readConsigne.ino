// #ifndef  PARAMETERS_H
// #include "parameters.h"
// #endif

bool readConsigne(int &targetPwm)
{
  static String inputString = "";
  static bool stringComplete = false;

  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    if (inChar == '\n')
    {

      stringComplete = true;
    }
    else
    {
      inputString += inChar;
    }
  }

  if (stringComplete)
  {
    targetPwm = convertConsigneToPwm(inputString.toInt());
    inputString = "";
    stringComplete = false;
    return true;
  }

  return false;
}

int convertConsigneToPwm(int consigne)
{
  return (handleMinMAX_CONSIGNE(consigne) * 255) / 100;
}
int convertPwmToPercent(int targetPwm)
{
  return (targetPwm * 100) / 255;
}
int handleMinMAX_CONSIGNE(int consigne)
{
  return consigne * (MAX_CONSIGNE - MIN_CONSIGNE) / 100 + MIN_CONSIGNE;
}
