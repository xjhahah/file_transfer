#include "server.h"
#include "Mysql.h"


int main()
{
  Mysql sql;
  
  sql.InitSql("localhost", "root", "xjh1998,.", "file");
  sql.CheckFile();
  sql.ExeSql("SELECT * FROM Infor;");

  Server ser;
  ser.server_Start();

  return 0;
}
