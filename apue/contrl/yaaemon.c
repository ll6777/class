#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include <syslog.h>

#define   LOCKFILE  "/var/run/daemon.pid"

int mydaemon(void);

int run_already(void);

int main(void)
{
	//将时间字符串 年月日 时分秒  写入/tem/out,  每过一秒写一次
	
	char buf[1000] = {};
	time_t t;
	struct tm *tmp;

/*	FILE *fp;     //标准IO打开的是文件流，有缓冲区
    标准io
	fp = fopen("/home/ll/class/apue/contrl/lllll.c" , "w");//打开文件

	for(int i = 0;  ; i++){

		time(&t);  //获取时间戳
		tmp = localtime(&t);  //以年月日表示
		memset(buf , '\n' , BUFSIZE);
		strftime(buf , 1000, "%Y %m %d :%H %M %S\n" , tmp);  //转化为格式字符串表示

		fputs(buf ,fp);  //把buf里面的数据 打印到 文件里
		fflush(NULL);   //刷新缓冲区

		sleep(1);
}
 		fclose(fp);  //关闭文件
*/	
	
/*	if(mydaemon() == -1){
		fprintf(stderr , "mydaemon  is faild\n");
		exit(1);
	}*/

	if(daemon(0,0) == -1){  //调用守护进程  需要先守护进程再单实例进程
		perror("daemon()");
		exit(1);
	}
	if(run_already() == -1){
		syslog(LOG_ERR , "run_already() failed");
		exit(1);
	}
	openlog(NULL , LOG_PID,LOG_DAEMON);  //通知系统我要写日志文件  

	int fp;   //系统IO打开的是文件描述符
	fp = open("/home/ll/class/apue/contrl/lllll.c" , O_WRONLY |O_CREAT |O_TRUNC,0666);
	if(-1 == fp){
		syslog(LOG_ERR,"open():%s" , strerror(errno));
		exit(1);
	}
	while(1){
		time(&t);
		tmp = localtime(&t);
		strftime(buf , 1000, "%Y %m %d :%H %M %S\n" , tmp);

		write(fp , buf , strlen(buf));  //把buf数组里面的数据写道文件fp 
		write(fp , "\n" , 1);

		syslog(LOG_INFO,"%s写入了lllll.c" , buf);
		sleep(1);

	}




	exit(0);
}


int mydaemon(void)
{
	pid_t pid;
	int fp;

	pid = fork();  //创建子进程
	if(pid == -1){
		perror("fork()"); //错误处理
		return -1;
	}
	if(pid > 0){
		exit(0); //关闭父进程
	}
	if(setsid() == -1){ //错误判断
		perror("setsid()");
		return -1;
	}
	umask(0);//屏蔽权限
	chdir("/");  //更改工作目录到/
	fp = open("/dev/null" , O_RDWR); 
	if(-1 ==fp){
		perror("open()");
		return -1;
	}
	dup2(fp,0);  //重定向0 1 2  
	dup2(fp,1);
	dup2(fp,2);
	if(fp > 2 ){ 
		close(fp); //为了保证0 1  2的正常使用
	}

	return 0;

}

int run_already(void)  //给子进程加锁
{
	int fd;
	char buf[1000] = {};
	
	fd = open(LOCKFILE , O_WRONLY | O_CREAT,0664);
	if(-1 ==fd){
		syslog(LOG_ERR,"open():%s" , strerror(errno));//写日志文件
		return -1;
	}
	if(lockf(fd,F_TLOCK,0 ) == -1){
		syslog(LOG_ERR , "lockf()%s" , strerror(errno));//写加锁失败原因
		close(fd);
		return -1;
	}
	ftruncate(fd , 0);  //把文件截断为0（相当于清空文件）
	snprintf(buf , 1000 , "%d" ,getpid());  //把pid写到buf里面
	write(fd , buf , strlen(buf));  //把buf写到文件里

	return 0;
}









