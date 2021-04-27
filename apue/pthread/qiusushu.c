#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include <unistd.h>



#define  A   100
#define  Z   300

static int iszhishu(int n)
{
	for(int i  = 2 ; i < n ; i++ )
		if(n%i == 0)
			return 0;
	return 1;
}

static void *thr_job(void *s)
{
	int n = (int)s;
	if(iszhishu(n))
		printf("%d  is a primer\n" ,n);
	pthread_exit((void *)0);
	
}

int main(void)
{
	int i;
	pthread_t tid[201] = {};
	int err;

	for(i = A ; i <= Z ; i++)  //父进程创建201个子进程
	{
		err = pthread_create(tid+i-A , NULL , thr_job, (void *)i);
		if(err){   //出错判断
			fprintf(stderr , "pthread_create():%s\n" , strerror(err));
			exit(1);  
		}

	}

	for(i = A ; i  <= Z ; i++)  //收尸
			pthread_join(tid[i - A],NULL );

	
	pthread_exit((void *)0);
}
