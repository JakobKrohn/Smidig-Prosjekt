


// CONNECT TO WIFI
bool connectWiFi(const char *ssid, const char *pass)
{
  Serial.print("\n* Attempting to connect to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  int t = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    t++;
    if (t >= 50) {
      Serial.println("\nConnection timed out");
      ConnectionSucceeded = false;
      return false;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnection established");
    ConnectionSucceeded = true;
    return true;
  }
}



void startAccessPoint()
{
  Serial.println(">> Configuring access point ");

  scanWiFi();
  setup_EEPROM();

  WiFi.softAP(AP_SSID);
  IP = WiFi.softAPIP();

  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Starting DNS server
  Serial.println("Starting DNS server");
  dnsServer.start(DNS_PORT, "*", IP);

  APserver.on("/", root);
  APserver.on("/generate_204", root); // Android captive portal
  APserver.on("/fwlink", root);       // Windows captive portal
  APserver.on("/reply", reply);
  APserver.begin();

  Serial.println("HTTP server started");


  while (true)
  {
    dnsServer.processNextRequest();
    APserver.handleClient();

    // If the Ap is up for over 20 minutes, go to sleep until the button is pressed
    if (millis() > 1200000)
    {
      Serial.print(F("Soft Access Point has been up for 20 minutes"));
      Serial.println(F(" - Press button to start up again"));
      ESP.deepSleep(0);
    }
  }
}

void scanWiFi()
{
  Serial.println(">> Scanning for networks ... ");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  ScannedNetworks = WiFi.scanNetworks();

  if (ScannedNetworks == 0) {
    Serial.println("No networks found");
    return;
  }

  Serial.print(ScannedNetworks);
  Serial.println(" networks found");

  Serial.println("Starting sorting...");

  //int indicies[ScannedNetworks];

  for (int i = 0; i < ScannedNetworks; i++)
  {
    indicies[i] = i;
  }

  // Sort networks by RSSI
  for (int i = 0; i < ScannedNetworks; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (WiFi.RSSI(indicies[j]) > WiFi.RSSI(indicies[i]))
      {
        std::swap(indicies[i], indicies[j]);
      }
    }
  }

  for (int i = 0; i < ScannedNetworks; ++i) {
    Serial.print(i + 1);
    Serial.print(": ");
    //Serial.print(WiFi.SSID(i));
    Serial.print(WiFi.SSID(indicies[i]));
    Serial.print(" (");
    //Serial.print(WiFi.RSSI(i));
    Serial.print(WiFi.RSSI(indicies[i]));
    Serial.println(")");
    delay(10);
  }

  // Remove duplicates
  for (int i = 0; i < ScannedNetworks; i++)
  {
    if (indicies[i] == -1)
      continue;
      
    String ssid = WiFi.SSID(indicies[i]);
    for (int j = i + 1; j < ScannedNetworks; j++)
    {
      if (ssid == WiFi.SSID(indicies[j]))
      {
        indicies[j] = -1;
      }
    }
  }

  Serial.println("\nRemoved duplicates");

  for (int i = 0; i < ScannedNetworks; ++i) 
  {
    if (indicies[i] == -1)
      continue;
    
    Serial.print(i + 1);
    Serial.print(": ");
    //Serial.print(WiFi.SSID(i));
    Serial.print(WiFi.SSID(indicies[i]));
    Serial.print(" (");
    //Serial.print(WiFi.RSSI(i));
    Serial.print(WiFi.RSSI(indicies[i]));
    Serial.println(")");
    delay(10);
  }
}


