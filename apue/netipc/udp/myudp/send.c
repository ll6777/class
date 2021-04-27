#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "proto.h"

int main(int argc , char *argv[])
{
	char buf[MSGMAX] = {};  //数据缓存区
	struct sockaddr_in raddr;

	if(argc < 2){
		exit(1);
	}

	int sd = socket(AF_INET , SOCK_DGRAM , 0); //创建套接字
	if(-1 == sd){
		perror("socket()");
		exit(1);
	}

	//发送
	raddr.sin_family = AF_INET;  //地址
	raddr.sin_port = htons(RCVPORT); //转化为网络字节序
	inet_aton(RCVIP , &raddr.sin_addr);  //点分十进制地址转化为地址结构体
	sendto(sd , argv[1] ,strlen(argv[1])+1 , 0, (struct sockaddr *)&raddr \
					,sizeof(raddr)); //发送信息
	close(sd);

	exit(0);


}



















