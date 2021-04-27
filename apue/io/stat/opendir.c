#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include <dirent.h>
#include<string.h>

#define   BUFSIZE  128

int main(int argc  , char *argv[])
{
	DIR *dp;
	struct dirent *entry;
	struct  stat res;
	char buf[BUFSIZE] = {};
	int sum = 0;

	if(argc  <  2){
		printf("缺少输入成员！！！\n");
		return 1;
	}
	if(stat(argv[1] , &res) == -1){   //判断获取argv[1]是否成功
		perror("stat()");
		return 1;
	}

	dp = opendir(argv[1]);   //打开argv[1]文件目录  成功返回目录  
	if(dp == NULL){
		perror("opendir()");  //失败返回空
		return 1;
	}
	while(1){
		entry  = readdir(dp); //读目录   成功返回下一个目录 
		if(entry == NULL){ //失败或读完都返回空
			if(!errno)  //错误是有错误代码
				break;
			perror("readdir()");
			goto READERROR;
		}

	memset(buf , '\0' , BUFSIZE);   //先将buf制为空
	strncpy(buf ,argv[1] , BUFSIZE );
	strcat(buf , "/" );
	strncat(buf , entry->d_name , BUFSIZE);
	if(stat(buf , &res)  == -1){
		perror("stat()");
		return 1;
	}
	sum += res.st_size;
	printf("%s\n",entry->d_name );
	}

	printf("%d\n" , sum);
	closedir(dp);

	return 0;
READERROR:
	closedir(dp);
	return 1;

}

















