#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler1(int s)
{
	write(1 , "!" , 1);
}

void handler2(int s)
{
	write(1 , "#" , 1);
}


int main(void)
{
	sigset_t set,oldset;

	signal(SIGINT , handler1); //改变信号行为
	signal(SIGQUIT , handler2);//改变信号行为

	sigemptyset(&set);  //把信号集置为空
	sigaddset(&set , SIGINT);  //添加信号
	sigaddset(&set , SIGQUIT);  //添加信号

	sigprocmask(SIG_BLOCK , &set , &oldset);//在每一行遍历之前屏蔽信号集

	for(int i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			write(1 , "*" , 1);
			sleep(1);
		}
		write(1 , "\n" , 1);

	sigsuspend(&oldset);
	//  相当于这三步骤
	//	sigprocmask(SIG_BLOCK, &oldset , &set);//恢复屏蔽字
	//	pause();
	//	sigprocmask(SIG_SETMASK , &set , NULL);
	}
	



}

