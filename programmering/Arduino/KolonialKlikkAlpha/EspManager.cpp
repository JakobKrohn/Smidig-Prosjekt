#include "EspManager.h"
#include "Keywords.h"
#include <Arduino.h>

// 70 minutes
unsigned int SLEEPTIME = 4200000000; 

EspManager::EspManager()
{
}

EspManager::~EspManager()
{
}

void EspManager::initialize()
{
    Serial.println("ESP initializing");

    _wifiManager.reset(new WifiManager());
    _eepromManager.reset(new EepromManager());
    _databaseManager.reset(new DatabaseManager());
    
    rst_info * rinfo = ESP.getResetInfoPtr();
    _resetInfo = rinfo->reason;

    Serial.print("Reset info: ");
    Serial.println(_resetInfo);
}

void EspManager::execute()
{
    Serial.println("ESP executing");

    // To delete SSID and password from the module
    //_eepromManager->clearSSID();
    //_eepromManager->clearPassword();

    if (_wifiManager->connect(_eepromManager->getSSID(), _eepromManager->getPassword()))
    {
        // We connected successfully!
        Serial.println("Connected successfully");

        if (_eepromManager->isSettingUp()) 
        {
            //_databaseManager->executeSqlQuery(EXECUTE_SETUP);
        }
        else if (_resetInfo == 0) 
        {
            //_databaseManager->executeSqlQuery(EXECUTE_ORDER);
        }
        else
        {
            //_databaseManager->executeSqlQuery(EXECUTE_PING);
        }
        
        if (_eepromManager->isSettingUp())  _eepromManager->markSetup(false);

        //ESP.deepSleep(SLEEPTIME, WAKE_RF_DEFAULT);
    }
    else
    {
        // We could not connect 
        Serial.println("Connection failed");
        
        if (_wifiManager->startAccessPoint())
        {
            // We recieved SSID and password thru access point
            _eepromManager->saveSSID(_wifiManager->getSSID());
            _eepromManager->savePassword(_wifiManager->getPassword());
            _eepromManager->markSetup(true);
            // ESP will now restart and try to connect to the new network
            ESP.restart();
        }
        else
        {
            // The access point timed out, ESP will go to sleep to save battery
            //ESP.deepSleep(0);
        }
    }
}



