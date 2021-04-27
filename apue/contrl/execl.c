#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
	pid_t pid;
	printf("%s  start\n" , __FUNCTION__);

	pid = fork();
	if(-1 == pid){   //出错判断
		perror("fork()");
		exit(1);  //释放fork
	}

	if(pid == 0){
//		execl("/bin/ls" , "ls" , "-l" , NULL);
//		execl("/home/ll/class/apue/contrl/fenkuai" ,"." , NULL);
//		execlp("ls" ,"ls" ,"-l", "-i", NULL);

		char *opts[] = {"ls" , "-l" , NULL};
		execv("/bin/ls" , opts);


		perror("execl()");//当execl有返回值表示出错
		exit(1);
	}

	wait(NULL);
	printf("%s    end\n" , __FUNCTION__);

	exit(0);
}









