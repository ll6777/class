#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	pid_t pid;
	int shmid;
	int created = 1;
	char *p;

	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | IPC_EXCL | 0600);  //创建共享内存
	if (shmid == -1) {
		if (errno == EEXIST) {   //重复创建出错
			shmid = shmget(IPC_PRIVATE, 1024, 0); //重新创建
			created = 0;
		} else {
			perror("shmget()");
			exit(1);
		}
	}

	pid = fork();  //创建子进程
	if (pid == -1) {
		perror("fork()");
		if (created)
			shmctl(shmid, IPC_RMID, NULL);  //删除共享内存
		exit(1);
	}
	if (pid == 0) {
		p = shmat(shmid, NULL, 0); //将共享内存连接到当前进程的地址空间
		strcpy(p, "hello world");
		shmdt(p); //将共享内存从当前进程分离出来
		exit(0);
	}
	wait(NULL);

	p = shmat(shmid, NULL, SHM_RDONLY);  //连接
	puts(p);
	shmdt(p);

	if (created)	
		shmctl(shmid, IPC_RMID, NULL);  //分离

	exit(0);
}

