#include "server.h"
#include "MySql.h"


int main()
{
  Mysql sql;
  
  sql.InitSql("47.92.211.160", "root", "123456", "file");
  sql.CheckFile();
  sql.ExeSql("SELECT * FROM Infor;");

  Server ser;
  ser.server_Start();

  return 0;
}
