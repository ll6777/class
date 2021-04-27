#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<glob.h>

int  parsestring(char *s, glob_t *res) //字符分割函数
{
	char *r;
	int i = 0;
	while(1){
		r = strtok(s," \n");  //字符分割
		if(r == NULL)  //分割结束返回为空
			break;
		glob(r ,GLOB_NOCHECK | GLOB_APPEND *i, NULL , res);//读目录
		s = NULL;
		i = 1;
	}
	return 0;
}

void mysystem(const char *s)
{
	glob_t res;
	pid_t pid;
	char *arr = malloc(strlen(s)+1);
	strcpy(arr,s);
	parsestring(arr,&res);

	pid =fork();
	if(-1 == pid){   //错误判断
			perror("fork()");
			exit(1);
		}
		if(pid == 0){ //成功返回子进程
			execvp((res.gl_pathv)[0],res.gl_pathv); //新进程执行指令
			perror("execvp()"); //报错处理
			exit(1);
		}
		puts((res.gl_pathv)[0]);
		wait(NULL);  //不管进程结束状态标志的收尸函数
		free(arr);  //释放getline开辟的空间
		arr = NULL;
}

int main(void)
{	
	mysystem("clear");
	printf("清屏\n");

	exit(0);
}










