#include "server.h"
#include "MySql.h"


int main()
{
  Mysql sql;
  sql.InitSql("localhost", "root", "123456", "file");
  sql.ExeSql("SELECT * FROM Infor;");
  return 0;
}
