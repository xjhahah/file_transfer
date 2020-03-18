#pragma once 

#include <iostream>
#include <string>
#include <mysql/mysql.h>


using namespace std;

class Mysql{
  public:
    Mysql();
    ~Mysql();

    bool InitSql(string host, string user, string pwd, string sqlName);
    bool ExeSql(string sql);

    void AddFile(const string& fileName,long long size);
    void CheckFile();
  private:
    MYSQL *_mysql;
    MYSQL_ROW _row;
    MYSQL_RES *_result;
    MYSQL_FIELD *_filed;
};
