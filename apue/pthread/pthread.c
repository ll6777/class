#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

static void exit_handler1(void *s)
{
	printf("%s  is  called\n" , __FUNCTION__);
}

static void exit_handler2(void *s)
{
	printf("%s  is  called\n" , __FUNCTION__);
}


static void *thr_job(void *s)
{
	pthread_cleanup_push(exit_handler1,NULL); //注册1  2  两个函数
	pthread_cleanup_push(exit_handler2,NULL);
	for(int i = 0 ; i < 5 ; i++){
		write(1 ,"*", 1);
		sleep(1);
	}
	
//	return (void *)0;
	pthread_exit((void *)0);
	pthread_cleanup_pop(0);  //与push 一一对应
	pthread_cleanup_pop(0);
}



int main(void)
{
	pthread_t tid;
	int err;
	pthread_attr_t attr;

	pthread_attr_init(&attr);  //创建线程之前将线程设置为分离状态
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	err = pthread_create(&tid , NULL ,thr_job , NULL);
	if(err){
		fprintf(stderr , "pthread_create():%s\n" , strerror(err));
		exit(1);
	}
	
	for(int i = 0 ; i < 3 ; i++)
	{
		write(1 , "@" , 1);
		sleep(1);
	}

//	pthread_join(tid , NULL);   //收尸函数    当线程分离出来就不用收尸了

	pthread_exit((void *)0);


//	return 0;
}





























