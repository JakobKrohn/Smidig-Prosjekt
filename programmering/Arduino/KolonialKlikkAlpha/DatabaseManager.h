#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <WiFiClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    void executeSqlQuery(int query);

private:
    char * USERNAME_SERVER =         "vesand16_klikk";
    char * PASSWORD_SERVER =         "KolonialKlikk";
    const char * ORDER_SQL =         "Update vesand16_kolonial_klikk.button SET buttonState=1 WHERE button_id=3";       // SQL query #1
    const char * PING_SQL =          "Update vesand16_kolonial_klikk.button SET isActive=1 WHERE button_id=3";          // SQL query #2
    const char * SETUP_SQL =         "Update vesand16_kolonial_klikk.button SET setupComplete=1 WHERE button_id=3";     // SQL query #3
    const IPAddress SERVER_IP =      {178, 62, 193, 44};

    WiFiClient          _client;
    MySQL_Connection *  _connection;

};

#endif // !DATABASE_MANAGER_H



