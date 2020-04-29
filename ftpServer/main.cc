#include "server.h"
#include "Mysql.h"


int main()
{
  Mysql sql;
  
flag:
  bool isOk = sql.InitSql("localhost", "root", "xjh1998,.", "file");
  if(isOk == true){
    sql.ExeSql("SELECT * FROM Info;");
    sql.CheckFile();
  }
  else{
    cout << "db init error" << endl;
    goto flag;
  }
  Server ser;
  ser.server_Start(sql);

  return 0;
}
