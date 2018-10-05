#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <ESP8266WebServer.h>
#include <DNSServer.h>

class WifiManager
{
public:
    WifiManager();
    ~WifiManager();

    bool connect(String ssid, String password);
    bool startAccessPoint();
    String getSSID() const;
    String getPassword() const;

private:
    const char * AP_SSID =          "Kolonial Klikk";
    const byte DNS_PORT =           53;
    const int CONNECTION_TIMEOUT =  60;

    DNSServer *         _dnsServer;
    ESP8266WebServer *  _webServer;
    IPAddress           _ipAddress;
    int                 _scannedNetworks[300];
    int                 _networksFound;
    bool                _fetchedInput;
    String              _SSID;
    String              _password;

    void scanWifi();
    void root();
    void reply();

};


#endif // !WIFI_MANAGER_H



