#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define  A   100
#define  B   300

static int iszhishu(int n)
{
	for(int i  = 2 ; i < n ; i++ )
		if(n%i == 0)
			return 0;
	return 1;
}


int main(void)
{
	pid_t pid;
	int i,j;

	for(i = A ; i < B ; i+=50)   //分4块进程处理
	{
		pid = fork();
		if(-1 == pid){
			perror("fork()");
			exit(1);
		}
	if(0 == pid){
		for( j = i ; j < i+50 ; j++){
			if(iszhishu(j))
				printf("[%d] %d是一个质数\n" , getpid() , j);
				}
			exit(0);
			}
	}
	for(i = 0 ; i  < 4 ; i++)
			wait(NULL);
	exit(0);
}

