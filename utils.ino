void printLog(String key, int value)
{
    Serial.print(key);
    Serial.println(value);
}

void printStatus(int targetPwm, int currentPwm)
{
    printLog("ConsignePwm = ", targetPwm);
    printLog("Pwm Mem = ", currentPwm);
    
}