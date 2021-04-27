#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
	int pid,ppid;
	int num = 100;
	pid = getpid();
	ppid = getppid();
	printf("pid: %d    ppid: %d\n", pid ,ppid);
	//创建子进程
	pid = fork();
	if(pid == -1){
		perror("fork()");
		exit(1);
	}
	if(pid == 0){ //两份进程同时进行    
			//子进程
			printf("pid: %d  ppid: %d\n",getpid(), getppid());
			printf("num:%d\n" , num);
			num = 2000;
			printf("num:%d\n" ,num );
			sleep(2);

			exit(0);
	}
/*	for(int i = 0 ; i < 3 ; i++) //调用进程
	{
		write(1 , "*" , 1);
		sleep(1);
	}*/

	wait(NULL);
	printf("你好啊！\n");
	printf("num:%d\n" , num);

	exit(0);	
}


