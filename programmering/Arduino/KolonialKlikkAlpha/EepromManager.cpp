#include "EepromManager.h"
#include <Arduino.h>
#include <EEPROM.h>

EepromManager::EepromManager()
{
    EEPROM.begin(512);
}

EepromManager::~EepromManager()
{
}

void EepromManager::clearSSID()
{
    Serial.println("Clearing SSID");
    
    for (int i = 0; i < 64; ++i)
    {
        EEPROM.write(i, 0);
    }

    EEPROM.commit();
}

void EepromManager::clearPassword()
{
    Serial.println("Clearing password");
    
    for (int i = 0; i < 128; ++i)
    {
        EEPROM.write(64 + i, 0);
    }

    EEPROM.commit();
}

void EepromManager::saveSSID(String ssid)
{
    Serial.print("Saving ssid: ");
    Serial.println(ssid);
    
    for (int i = 0; i < ssid.length(); ++i)
    {
        EEPROM.write(i, ssid[i]);
    }
    
    EEPROM.commit();
}

void EepromManager::savePassword(String password)
{
    Serial.print("Saving password: ");
    Serial.println(password);
    
    for (int i = 0; i < password.length(); ++i)
    {
        EEPROM.write((64 + i), password[i]);
    }
    
    EEPROM.commit();
}

String EepromManager::getSSID() const
{
    Serial.print("Reading ssid: ");

    String ssid = String();

    for (int i = 0; i < 64; ++i)
    {
        char c = char(EEPROM.read(i));

        if (c == '0') break;
        else ssid += c;
    }

    Serial.println(ssid);

    return ssid;
}

String EepromManager::getPassword() const
{
    Serial.print("Reading password: ");

    String password = String();

    for (int i = 64; i < 128; ++i)
    {
        char c = char(EEPROM.read(i));

        if (c == '0') break;
        else password += c;
    }

    Serial.println(password);

    return password;
}

void EepromManager::markSetup(bool setup)
{
    if (setup)
    {
        Serial.println("Marking setup");
        EEPROM.write(511, '1');
        EEPROM.commit();
    }
    else
    {
        Serial.println("Marking normal");
        EEPROM.write(511, '0');
        EEPROM.commit();
    }
}

bool EepromManager::isSettingUp() const
{
    char ret = char(EEPROM.read(511));

    if (ret == '1') return true;
    else return false;
}






