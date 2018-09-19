#include <Arduino.h>
#include "TOTP++.h"

using namespace std;

// TOTP CONFIG
TOTP totp = TOTP();
string key = "JBSWY3DPEHPK3PXP";
long GMT = 1536272457;
char code[6];

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    
    char *newCode = totp.getCode(key, 30, GMT);
    if (strcmp(code, newCode) != 0 && GMT != 0)
    {
        // TESTED WITH: https://totp.danhersam.com/
        strcpy(code, newCode);
        Serial.println("---> ORIGINAL[863491]");
        Serial.print("---> CODE[");
        Serial.print(code);
        Serial.println("]");
        delay(1000);
    }
}