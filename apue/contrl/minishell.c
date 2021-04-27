#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <glob.h>
#include <sys/wait.h>
#include <string.h>


int  parsestring(char *p, glob_t *res) //字符分割函数
{
	char *r;
	int i = 0;
	while(1){
		r = strtok(p," \n");  //字符分割
		if(r == NULL)  //分割结束返回为空
			break;
		glob(r ,GLOB_NOCHECK | GLOB_APPEND *i, NULL , res);//读目录
		p = NULL;
		i = 1;
	}
}


int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	glob_t str;
	pid_t pid;

	while(1){
		printf("[%s]$ " , getenv("PWD")); //打印当前路径
		if(getline(&lineptr , &n, stdin) == -1) //获得标准输入的一行数据（-1是读完或者出错）
			break;
		//strsep(3)   / strtok(3):
		 //lineptr---->str
		if(strcmp(lineptr, "exit\n") == 0){ //如果输入了exit就退出
			free(lineptr);  //释放getline开辟的空间
			lineptr = NULL;
			break;
		}
		parsestring(lineptr,&str);  //调用字符分割函数

		pid = fork();  //创建子进程
		if(-1 == pid){   //错误判断
			perror("fork()");
			exit(1);
		}
		if(pid == 0){ //成功返回子进程
			execvp((str.gl_pathv)[0],str.gl_pathv); //新进程执行指令
			perror("execvp()"); //报错处理
			exit(1);
		}

		wait(NULL);  //不管进程结束状态标志的收尸函数
		free(lineptr);  //释放getline开辟的空间
		lineptr = NULL;
		n = 0;  //n置为0
	}




	exit(0);
}
		






