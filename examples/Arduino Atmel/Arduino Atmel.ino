// This example uses the opensource SwRTC library as a software real-time clock
// you can download from https://github.com/leomil72/swRTC
// for real implementation it's suggested the use of an hardware RTC

#include <Arduino.h>
#include "TOTP++.h"
#include "swRTC.h"

using namespace std;

// TOTP CONFIG
TOTP totp = TOTP();
string key = "JBSWY3DPEHPK3PXP";
char code[6];

void setup()
{
    Serial.begin(9600);
    rtc.stopRTC();

    // Adjust the following values to match the current date and time
    // and power on Arduino at the time set (use GMT timezone!)
    rtc.setDate(27, 8, 2013);
    rtc.setTime(21, 25, 00);
    rtc.startRTC();
}

void loop()
{

    long GMT = rtc.getTimestamp();
    char *newCode = totp.getCode(key, 30, GMT);
    if (strcmp(code, newCode) != 0 && GMT != 0)
    {
        // TESTED WITH: https://totp.danhersam.com/
        strcpy(code, newCode);
        Serial.print("----> CODE[");
        Serial.print(code);
        Serial.println("]");
        delay(1000);
    }
}