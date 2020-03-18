#include "MySql.h"

bool Mysql::InitSql(string& host, const string& user, const string& pwd, const string& sqlName){
  //连接数据库
  //连接成功返回MYSQL*连接句柄，即sql服务器
  if(!mysql_real_connect(_mysql, host.c_str(), user.c_str(), pwd.c_str(), sqlName.c_str(), 0 , nullptr , 0)){
    cout << "sql connect fail!,error message: " << mysql_error(_mysql);
    exit(-1);
  } 
  return true;
}

//退出关闭数据库描述符
bool Mysql::ExeSql(const string& sql){
  //执行失败
  if(mysql_query(_mysql, sql.c_str())){
    //执行指定以NULL终结的字符串查询的SQL语句，返回一个结果表
    //成功可调用mysql_num_rows() 来查看对应于SELECT 语句返回了多少行
    cout << "sql query fail! error message: " << mysql_error(_mysql);
    exit(-1);
  }else{ //获取结果集
    _result = mysql_store_result(_mysql); //检索完整的结果保存至客户端

    int fieldNums = mysql_num_fields(_result); //返回结果集中的字段数，失败返回 false

    for(int i = 0; i < fieldNums; ++i){
      _row = mysql_fetch_row(_result); // 从结果集中获取下一行，成功返回一个数组，值大于0
      if(!_row){
        break;
      }
      for(int j = 0; j < fieldNums; ++j){
        cout << _row[j] << "\t\t";
      }
      cout << endl;
    }
    mysql_free_result(_result);
  } 
  return true;
}
