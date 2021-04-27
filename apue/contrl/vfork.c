#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
	pid_t pid;
	int num = 100;
	pid = vfork();
	if(-1 == pid ){
		perror("vfork()");
		exit(1);
	}
	if(0 == pid){
		num++;
		printf("[%d]   %d\n" , getpid() , num);
		sleep(2);
		_exit(0);

	}

	
	wait(NULL);
	printf("[%d]  %d\n" , getpid() , num);

	exit(0);
}
