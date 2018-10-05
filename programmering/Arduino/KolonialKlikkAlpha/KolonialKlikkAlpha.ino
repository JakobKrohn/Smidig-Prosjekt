#include "EspManager.h"

void setup() 
{
    Serial.begin(115200);

    delay(1000);

    Serial.println("Setup");

    EspManager espManager;
    espManager.initialize();
    espManager.execute();
}

// Since all necessary work are done in setup
//      this method will never be called. 
void loop(){}


