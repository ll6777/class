/*
有5个任务进程   分别向标准输出循环打印abcde
现在整个程序执行5秒    如何使得终端打印的字符串是有序的abcdeabcdeabcde
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THRNR	5   //5个线程

static int cur_id = 0; 
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; //初始化互斥量
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  //初始化条件

static pthread_t tids[THRNR] = {};

static void *thr_job(void *s)
{
	int id = (int)s;

	while (1) {
		pthread_mutex_lock(&mut);  //抢锁
		while (cur_id != id) {
			pthread_cond_wait(&cond, &mut);  //等待信号到来   解锁
		}
		printf("%c", 'a'+id);
		fflush(NULL); //刷新缓存区
		cur_id = -1;
		pthread_cond_broadcast(&cond); //广播
		pthread_mutex_unlock(&mut);  //解锁
	}

}

int main(void)
{
	pthread_t tids[THRNR] = {};
	int err;

	for (int i = 0; i < THRNR; i++) {
		err = pthread_create(tids+i, NULL, thr_job, (void *)i); //创建
		// if error;
	}

	alarm(5);//计时器   5秒后发送SIGALARM 信号

	for (int i = 0; i < THRNR; i = (i+1) % THRNR) {
		pthread_mutex_lock(&mut);  //抢锁
		while (cur_id != -1) {
			pthread_cond_wait(&cond, &mut); //等待信号到来  解锁
		}
		cur_id = i;
		pthread_cond_broadcast(&cond); //广播
		pthread_mutex_unlock(&mut); //解锁
	}

	exit(0);
}









