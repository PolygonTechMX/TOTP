#include <Arduino.h>
#include "TOTP++.h"

using namespace std;

// TESTED WITH: https://totp.danhersam.com/

long GMT = 1536272457;
TOTP totp = TOTP();
string key = "JBSWY3DPEHPK3PXP";
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
        strcpy(code, newCode);
        Serial.println("----> ORIGINAL[863491]");
        Serial.print("----> NEW CODE[");
        Serial.print(code);
        Serial.println("]");
        delay(1000000);
    }
}