#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "proto.h"



int main(void)
{
	struct sockaddr_in  laddr;
	char buf[MSGMAX] = {}; //缓存区
	struct sockaddr_in raddr;
	socklen_t raddrlen;
	int cnt;

	int sd = socket(AF_INET, SOCK_DGRAM, 0); //创建套接字
	if (-1 == sd) {
		perror("socket()");
		exit(1);
	}
// 绑定地址
	laddr.sin_family = AF_INET;  //地址族   通常是AF_INET
	laddr.sin_port = htons(RCVPORT);   //将本地字节序转化为网络字节序
	inet_aton(RCVIP, &laddr.sin_addr); // 点分十进制地址转换为地址结构体
	if (bind(sd, (struct sockaddr *)&laddr, sizeof(laddr)) == -1) { //绑定
		perror("bind()");
		goto ERROR;
	}

	// 对端地址长度必须初始化
	raddrlen = sizeof(struct sockaddr_in);  //接收到的地址长度
	while (1) {
		memset(buf, '\0', MSGMAX);  // 清空缓存区
		cnt = recvfrom(sd, buf, MSGMAX, 0, (struct sockaddr *)&raddr, &raddrlen);	 //接收信息
		if (cnt == -1) {  //接收失败
			perror("recvfrom()");
			goto ERROR;
		}

		if (strcmp(buf, "exit") == 0)  //自定义退出
			break;

		printf("remote addr:%s %d\n", inet_ntoa(raddr.sin_addr),\
				ntohs(raddr.sin_port)); //打印ip地址  和网关
		printf("data:%s\n", buf);  //打印接收信息
	}

	close(sd);

	exit(0);
ERROR:
	close(sd);
	exit(1);







}














