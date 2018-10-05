#ifndef ESP_MANAGER_H
#define ESP_MANAGER_H

extern "C"  
    #include <user_interface.h>

#include "WifiManager.h"
#include "EepromManager.h"
#include "DatabaseManager.h"
#include <memory>

class EspManager
{
public:
    EspManager();
    ~EspManager();

    void initialize();
    void execute();

private:
    std::shared_ptr<WifiManager>        _wifiManager;
    std::shared_ptr<EepromManager>      _eepromManager;
    std::shared_ptr<DatabaseManager>    _databaseManager;
    int                                 _resetInfo;
};


#endif // !ESP_MANAGER_H



