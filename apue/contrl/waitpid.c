#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
//waitpid()使用示例

int main(void)
{
    pid_t pid,ret;//
    printf("main process pid = %d\n",getpid());
    pid = fork();//创建子进程
    if(pid < 0)
    {
        printf("error fork\n");
    }
    if(pid == 0)//子进程
    {
		setpgid(getpid() , getpid());
        printf(" pid:%d, pgid : %d\n",getpid()  getpgid());
        exit(0);
    }
		printf("parent pid:%d , pgid:%d\n" , getpid() , getpgid());
		wait_pid = waitpid(-pid, NULL , 0);

       
    }

}

















