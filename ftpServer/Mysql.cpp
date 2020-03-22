#include "Mysql.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


bool Mysql::InitSql(string& host, const string& user, const string& pwd, const string& sqlName){
  //连接数据库
  //连接成功返回MYSQL*连接句柄，即sql服务器
  if(!mysql_real_connect(_mysql, host.c_str(), user.c_str(), pwd.c_str(), sqlName.c_str(), 0, nullptr, 0)){
    cout << "sql connect fail!,error message: " << mysql_error(_mysql);
    exit(-1);
  }else{
    cout << "sql connected success..." << endl;
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
    //mysql_free_result(_result);
  } 
  return true;
}

void  Mysql::CheckFile(){
  cout << "star check filepath is ok or no ok" << endl;

  const char *path = "/home/xjh/file_transfer";


  //Linux下遍历目录： 打开目录---》读取内容 ---》 关闭目录
  DIR *dp;

  struct dirent *entry; //定义文件操作句柄

  if((dp = opendir(path)) == NULL){
    cerr << "cannot open server file..." << endl;
    return ;
  }else{
    cout << "open it success" << endl;
  }


  while((entry = readdir(dp)) != NULL){
    cout << entry->d_name << endl;

    if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0){
      continue;
    }

    char path_file[100] = "/home/xjh/file_transfer";
    char name[100] = "";

    sprintf(name, "%s", entry->d_name);
    strcat(path_file, name);
    cout << path_file << endl;

    struct stat stbuf;

    int res = stat(path_file, &stbuf);

    printf("%8ld  %s\n", stbuf.st_size, name);
    
    AddFile(stbuf.st_size, name);
  }
  closedir(dp);
}


void Mysql::AddFile(long long size, char* name){
  char cmd[1024] = "";
  sprintf(cmd, "INSERT INTO ftpData values('%s','%d');", name, size);
  puts(cmd);
  if(mysql_real_query(_mysql, cmd, strlen(cmd)));{
    cerr << "0 query fail, message: " << mysql_error(_mysql);
    return ;
  }
}
