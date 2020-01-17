#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>

#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <unordered_map>

using namespace std;

//建立套接字
class Sock{
  public:
    // 1.初始化Sock
    Sock(int sock = -1,const int& port)
      :_sock(sock)
       ,_port(port)
    {}
    // 2.创建套接字
    void Socket(){
      _sock = socket(AF_INET,SOCK_STREAM,0);
      if(_sock < 0) {
          ceer << " socker error" << endl;
	      exit(2);
      }      
    }
    void Bind(){

    }
  private:
    int _sock;  //套接字
    int _port;  //端口号
};
