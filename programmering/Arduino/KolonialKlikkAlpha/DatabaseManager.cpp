#include "DatabaseManager.h"
#include "Keywords.h"
#include <Arduino.h>

DatabaseManager::DatabaseManager()
{
    _connection = new MySQL_Connection((Client *) &_client);
}

DatabaseManager::~DatabaseManager()
{
    delete(_connection);
}

void DatabaseManager::executeSqlQuery(int query)
{
    Serial.println("Executing SQL query");
    
    while (_connection->connect(SERVER_IP, 3306, USERNAME_SERVER, PASSWORD_SERVER) != true)
    {
        Serial.print(".");
        delay(200);
    }

    Serial.println();

    MySQL_Cursor * cursor = new MySQL_Cursor(_connection);

    if (query == EXECUTE_ORDER)
    {
        cursor->execute(ORDER_SQL);
        Serial.println("Order query finished");
    }
    else if (query == EXECUTE_PING)
    {
        cursor->execute(PING_SQL);
        Serial.println("Ping query finished");
    }
    else if (query == EXECUTE_SETUP)
    {
        cursor->execute(SETUP_SQL);
        Serial.println("Setup query finished");
    }
    else
    {
        cursor->execute(PING_SQL);
        Serial.println("Ping query finished");
    }

    delete(cursor);

    _client.stop();
}


