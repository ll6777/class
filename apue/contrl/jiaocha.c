#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define   A   100
#define   B	  300
#define   N    3

static int iszhishu(int n)
{
	for(int i  = 2 ; i < n ; i++ )
		if(n%i == 0)
			return 0;
	return 1;
}

int main(void)
{
	int i,n,mark;
	pid_t pid;

	for( n = 0 ;n < N ; n++)  //交叉分配给3个进程
	{
		pid = fork();
		if(-1 == pid){
			perror("fork()");
			exit(1);
		}
		if(0 == pid){
			for( i = A+n ; i <= B ; i+=N){
			if(iszhishu(i))
				printf("[%d] %d是一个质数\n" , getpid() , i);
		
				}
			exit(0);
		}

	}
	for(n = 0 ; n < N ; n++)
		wait(NULL);


	exit(0);
}
