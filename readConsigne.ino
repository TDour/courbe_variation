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
    Serial.print('FIN'); gyvu

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
  return (handleMinMaxConsigne(consigne) * 255) / 100;
}

int handleMinMaxConsigne(int consigne)
{
  return consigne * (maxConsigne - minConsigne) / 100 + minConsigne;
}
