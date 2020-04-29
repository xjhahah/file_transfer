#include "server.h"

#include "Mysql.h"

#define PORT 8080
const int LISTEN_NUM = 5;

Mysql mysql; //实例一个数据库对象

void Server::server_Start(Mysql  sql){

  //1.启动数据库
  mysql = sql;
  cout << "creating sockfd..." << endl;
  
  //2.创建套接字
  _sockfd = creat_socket();

  //3.指令处理
  handle_message(_sockfd);
}

//创建套接字
int Server::creat_socket(){

  int listen_sock = socket(AF_INET,SOCK_STREAM,0);

  if(listen_sock == -1){
    cerr << "sock create error: " << errno << endl;
    return -1;
  }

  int opt = 1;
  setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  struct sockaddr_in local;
  memset(&local, 0, sizeof(local));
  local.sin_family = AF_INET;
  local.sin_port = htons(PORT);
  local.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0){
    cerr << "bind socket error " << endl;
    exit(1);
  }

  if(listen(listen_sock,LISTEN_NUM) < 0){
    cerr << "listen error " << endl;
    exit(2);
  }

  cout << "start Listening..." << endl;
  return listen_sock;
}


//一旦监听套接字成功，开始进行message_handle
void Server::handle_message(int sockfd){

}



