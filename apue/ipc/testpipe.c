/*
	父进程讲argv[1]文件陆续写入管道，子进程读管道数据并大小写转换写到终端 
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE	10

int changeStr(char *p);
int copyFile(int rfd, int wfd, int flag);
int main(int argc, char *argv[])
{
	int fd;
	int pfd[2];
	pid_t pid;

	if (argc < 2)
		exit(1);

	fd = open(argv[1], O_RDONLY);  //打开argv【1】文件（只读）
	if (fd == -1) {
		perror("open()");
		exit(1);
	}

	if (pipe(pfd) == -1) { //创建管道
		perror("pipe()");
		goto ERROR1;
	}

	pid = fork();   //创建父进程
	if (pid == -1) {
		perror("fork()");
		goto ERROR2;
	}

	if (pid == 0) {  //子进程创建成功
		close(pfd[1]);   //关闭管道写端
		copyFile(pfd[0], 1, 1);  //读管道 写到缓存区
		close(pfd[0]);   //关闭读端
		exit(0);
	}
        //父进程
	close(pfd[0]);  //关闭管道读端
	copyFile(fd, pfd[1], 0); //读文件  写到管道
	close(pfd[1]);  //关闭管道写端

	wait(NULL);

	exit(0);
ERROR2:
	close(pfd[0]);
	close(pfd[1]);
ERROR1:
	close(fd);
	exit(1);
}

// copy file
int copyFile(int rfd, int wfd, int flag)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while (1) {
		memset(buf, '\0', BUFSIZE);  //清空缓存区
		cnt = read(rfd, buf, BUFSIZE-1);  //读   写到缓存区
		if (cnt == -1) {   //读失败
			return errno;
		}
		if (cnt == 0) //读完
			break;
		if (flag)   //判断标记
			changeStr(buf);  //大小写转换
		write(wfd, buf, cnt);  //把缓存区内容写到wfd
	}

	return 0;
}

int changeStr(char *p)
{
	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {  //大写转小写
			*p = *p + ('a'-'A');
		}
		else if (*p >= 'a' && *p <= 'z') { //小写转大写
			*p = *p - ('a'-'A');
		}
		p++;
	}

	return 0;
}








