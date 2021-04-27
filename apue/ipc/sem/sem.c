#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

static int semid;

static  int P(void);
static  int V(void);
int main(void)
{
	int fd;
	pid_t pid;
	int i,j,cnt;
	char buf[100] = {};
	int ret;

	
	fd = open("/home/ll/class/apue/ipc/sem/llll.c" ,O_RDWR | O_CREAT | O_TRUNC , 0666);
	if(-1 == fd){
		perror("open()");
		exit(1);
	}
	write(fd , "0" , 1);

	semid = semget(IPC_PRIVATE , 1 , IPC_CREAT | IPC_EXCL | 0600);
	if(semid == -1){
		perror("semget()");
		close(fd);
		exit(1);
	}
	semctl(semid , 0 , SETVAL , 1);  //设置一个信号

	


	for( i = 0 ; i < 20 ; i++){
		pid = fork();
		if(-1 == pid){
			perror("fork()");
			exit(1);
		}
		if(pid == 0){
			ret = P();  //取信号
			if(ret < 0){
				fprintf(stderr , "P():%s\n" , strerror(-ret));
				exit(1);
			}
			lseek(fd , 0 , SEEK_SET);
			cnt = read(fd , buf , 100);
			if (cnt == -1) {
			perror("read()");
			close(fd);
			return 1;
		}
			snprintf(buf , 100 ,"%d" , atoi(buf)+1);
			lseek(fd , 0 , SEEK_SET);
			write(fd , buf ,strlen(buf));
			V();  //还信号
			close(fd);
			exit(0);
		}

	}
	for(j = 0 ; j < 20 ; j++){
	wait(NULL);
	}

	close(fd);
	exit(0);


}

static  int P(void)
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_op = -1;
	buf.sem_flg = 0;

	if(semop(semid , &buf , 1) == -1){
		return -errno;
	}
	return 0;
}

static  int V(void)
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = 0;

	if(semop(semid , &buf , 1) == -1){
		return -errno;
	}
	return 0;
}







