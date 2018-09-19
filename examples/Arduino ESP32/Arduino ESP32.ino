#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include "TOTP++.h"

using namespace std;

// TOTP CONFIG
TOTP totp = TOTP();
string key = "JBSWY3DPEHPK3PXP";
char code[6];

// TIME CONFIG
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 0;

// WIFI CONFIG
const char *ssid = "DM";
const char *password = "1234123412";

void printLocalTime()
{
    time_t now;
    time(&now);
    Serial.print("--> UNIX[");
    Serial.print(now);
    Serial.println("]");
}

void setup()
{
    Serial.begin(9600);

    //connect to WiFi
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" CONNECTED");

    //init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();

    //disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
}

void loop()
{

    long GMT;
    char *newCode = totp.getCode(key, 30, GMT);
    if (strcmp(code, newCode) != 0 && GMT != 0)
    {
        // TESTED WITH: https://totp.danhersam.com/
        strcpy(code, newCode);
        Serial.print("---> CODE[");
        Serial.print(code);
        Serial.println("]");
    }
}