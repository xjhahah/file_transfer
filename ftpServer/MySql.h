#pragma once 

#include <iostream>
#include <string>
#include <mysql/mysql.h>


using namespace std;

class Mysql{
  public:
    Mysql(){
      _mysql = mysql_init(nullptr);
      if(nullptr != _mysql){
        cerr << "sql init error: " << mysql_error(_mysql);
        exit(-1);
      }
    }

    ~Mysql(){
      if(!_mysql){
        mysql_close(_mysql);
      }
    }

    bool InitSql(string& host,const string& user,const string& pwd,const string& sqlName);
    bool ExeSql(const string& sql);

    void AddFile(const string& fileName,long long size);
    void CheckFile();
  private:
    MYSQL *_mysql;
    MYSQL_ROW _row;
    MYSQL_RES *_result;
    MYSQL_FIELD *_filed;
};
