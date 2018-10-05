#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <Arduino.h>

class EepromManager
{
public:
    EepromManager();
    ~EepromManager();

    void clearSSID();
    void clearPassword();
    void saveSSID(String ssid);
    void savePassword(String password);
    String getSSID() const;
    String getPassword() const;
    void markSetup(bool setup);
    bool isSettingUp() const;

};


#endif // !EEPROM_MANAGER_H



