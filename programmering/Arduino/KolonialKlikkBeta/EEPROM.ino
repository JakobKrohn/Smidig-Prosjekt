

bool read_EEPROM()
{
  Serial.println(">> Reading EEPROM ");

  // EEPROM SSID
  for (int i = 0; i < 32; ++i) {
    EEPROM_SSID += char(EEPROM.read(i));
    if (EEPROM_SSID[0] == NULL) {
      Serial.println("EEPROM is empty");
      return false;
    }
  }

  Serial.print("EEPROM SSID: ");
  Serial.println(EEPROM_SSID);

  // EEPROM PASS
  for (int i = 32; i < 96; ++i)
  {
    EEPROM_PASS += char(EEPROM.read(i));
  }

  Serial.print("EEPROM PASS: ");
  Serial.println(EEPROM_PASS);

  if (EEPROM_SSID.length() > 1) {
    Serial.println("EEPROM contains configuration");
    return true;
  }
  return false;
}

void clear_EEPROM()
{
  Serial.println(">> Clearing EEPROM ");

  //for (int i = 0; i < 96; ++i) {
  for (int i = 0; i < 512; ++i) {
    EEPROM.write(i, 0);
  }

  Serial.println("EEPROM cleared");
}

void write_EEPROM(String ssid, String pass)
{
  Serial.println(">> Writing EEPROM ");

  Serial.print("Writing ssid: ");
  Serial.println(ssid);

  for (int i = 0; i < ssid.length(); ++i) {
    EEPROM.write(i, ssid[i]);
    Serial.print(ssid[i]);
    Serial.println(" -> EEPROM");
  }

  Serial.print("Writing password: ");
  Serial.println(pass);

  for (int i = 0; i < pass.length(); ++i) {
    EEPROM.write(32 + i, pass[i]);
    Serial.print(pass[i]);
    Serial.println(" -> EEPROM");
  }

  Serial.println("Finished");
  EEPROM.commit();
}

// RETURNS TRUE FOR SETUP
// RETURNS FALSE FOR NORMAL
bool getSetup_EEPROM()
{
  Serial.println(">> Getting setup values from EEPROM");

  char EEPROM_c = char(EEPROM.read(511));

  if (EEPROM_c == '1') {
    Serial.println("EEPROM is market at setup");
    return true;
  }
  else if (EEPROM_c == '0') {
    Serial.println("EEPROM is market as normal");
    return false;
  }
  else if (EEPROM_c == 0 || EEPROM_c == NULL) {
    Serial.println("EEPROM is empty");
    return false;
  }
  else {
    Serial.println("ERROR :: EEPROM contains garbage(?)");
    return false;
  }
}

void increment_counter_EEPROM()
{
  Serial.println(">> Incrementing counter to EEPROM");

  int oldCount = get_counter_EEPROM();
  oldCount++;

  EEPROM.write(500, oldCount);
}

int get_counter_EEPROM()
{
  Serial.println(">> Counter value from EEPROM is: ");
  Serial.print(" [ ");

  int value = EEPROM.read(500);

  Serial.print(value);
  Serial.println(" ] ");
}

// PUT ESP IN SETUP MODE
void setup_EEPROM()
{
  Serial.println(">> Marking setup to EEPROM ");

  EEPROM.write(511, '1');
  EEPROM.commit();
  Serial.println("Done");
}

// PUT ESP TO NORMAL MODE
void normal_EEPROM()
{
  Serial.println(">> Marking normal to EEPROM ");

  EEPROM.write(511, '0');
  EEPROM.commit();
  Serial.println("Done");
}


