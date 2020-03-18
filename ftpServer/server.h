#pragma once 

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <assert.h>

//网络接口所需头文件
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>


#include <mysql/mysql.h>

using namespace std;

class Mysql; 

class Server{
  public:
    Server()
    {}
    //1.启动服务器
    void server_Start(Mysql sql);
    //2.创建套接字
    int creat_socket();
    //3.接收文件
    void Receive_file(string s,int size);
    //4.发送文件
    void Sebd_file(string s,int size);
    //5.消息处理函数
    void Message_handle(int sockfd);
    //6.列表展示
    void List_file(string s,int size);
  private:
    int _sockfd;
};
