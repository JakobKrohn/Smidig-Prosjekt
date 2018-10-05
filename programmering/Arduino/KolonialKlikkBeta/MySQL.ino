
void update_SQL_server() 
{
  Serial.println(">> Connecting to SQL server");

  while (conn.connect(serverAddress, 3306, user, pass) != true)
  {
    delay(200);
  }

  Serial.println("Connected to SQL server");

  Serial.println("Executing SQL query");
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  if (buttonPressed)
  {
    cur_mem -> execute(ORDER_SQL);
  }
  else
  {
    cur_mem -> execute(PING_SQL);
  }

  delete cur_mem;

  Serial.println("Disconnecting from server");
  client.stop();

  OrderPlaced = true;
}
