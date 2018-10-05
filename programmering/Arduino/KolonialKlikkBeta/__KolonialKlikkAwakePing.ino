#include <Esp.h>
#include "ESP8266WiFi.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <EEPROM.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

extern "C" {
#include <user_interface.h>
}


// SERVER CONFIG
//WiFiServer server(80);  // localhost
WiFiServer server(2083);  // server skole
WiFiClient client;
MySQL_Connection conn((Client *)&client);
//IPAddress serverAddress(192, 168, 10, 169); // home
//IPAddress serverAddress(192, 168, 43, 44); // mobil
IPAddress serverAddress(178, 62, 193, 44); // server skole

//char user[] = "Button";
char user[] = "vesand16_klikk";
//char pass[] = "";
char pass[] = "KolonialKlikk";
//char ORDER_SQL[] = "Update button.click SET Click=1 WHERE ID=1";
char ORDER_SQL[] = "Update vesand16_kolonial_klikk.button SET buttonState=1 WHERE button_id=1";
//char PING_SQL[] = "Update button.click SET Active=1 WHERE ID = 1";
char PING_SQL[] = "Update vesand16_kolonial_klikk.button SET isActive=1 WHERE button_id=1";
bool OrderPlaced = false;

// DNS
DNSServer dnsServer;
const byte DNS_PORT = 53;

// ACCESS POINT
ESP8266WebServer APserver(80);
IPAddress IP;
const char *AP_SSID = "Kolonial Klikk";

int ScannedNetworks = 0;
int indicies[300];
bool ConnectionSucceeded = false;
bool SucceededInput = false;

String EEPROM_SSID;
String EEPROM_PASS;

bool buttonPressed = false;


// Max microseconds: 4294967295 - 71.5 min
// 70 min: 4200000000
// 2 min: 120000000
// 1 min: 60000000
// 30 sec: 20000000

unsigned int SLEEPTIME = 20000000;


void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512);

  delay(1000);

  long start = millis();

  Serial.println("\n");
  Serial.println("Setup started");
  Serial.println("");

  rst_info * rinfo = ESP.getResetInfoPtr();
  int rst = rinfo->reason;

  Serial.println("==========");
  Serial.print(F("Reset Info: "));
  Serial.println(rinfo->reason);
  Serial.println(F("=========="));

  if (rinfo->reason == 5)
  {
    Serial.println(F("Woke up from sleep"));
    buttonPressed = false;
  }
  else
  {
    Serial.println(F("Button pressed"));
    buttonPressed = true;
  }

  //clear_EEPROM();
  //EEPROM.end();

  ConnectionSucceeded = false;
  OrderPlaced = false;

  // Check if EEPROM contains some data
  if (read_EEPROM())
  {
    // Check if we can establish connection with wifi
    if (connectWiFi(EEPROM_SSID.c_str(), EEPROM_PASS.c_str()))
    {
      // Check if the button is in setup mode
      if (getSetup_EEPROM())
      {
        normal_EEPROM();
        Serial.println("Im done setting up");
      }
      // Otherwise, update the database
      else
      {
        update_SQL_server();
      }
      // Job finished, go to sleep
      Serial.println(F("Setup finished -- going to sleep"));
      long stoptime = millis();
      long timeUsed = stoptime - start;
      Serial.print("Time used: ");
      Serial.println(timeUsed); 
      ESP.deepSleep(SLEEPTIME, WAKE_RF_DEFAULT);
    }
  }

  startAccessPoint();
}

void loop()
{
}












