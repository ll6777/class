#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);


static void handler(int s)
{
	printf("arg:%d \n" , s);
	
	for(int i = 0 ; i < 3 ; i++){
		write(1 , "!" , 1);
		sleep(1);
	}

}



int main(void)
{
	int i = 0;
	struct   sigaction act , oldact;
	sighandler_t  sig = signal(SIGINT ,handler);//接收更改信号更改前的信号
//	signal(SIGQUIT , handler);
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask );
	sigaddset(&act.sa_mask,SIGINT);
	sigaction(SIGQUIT , &act , &oldact);


//	sleep(10);
			
	while(1){
		if(i > 10)
		{
			signal(SIGINT , sig);//  10秒之后 恢复更改信号的使用
		}
		write(1, "*", 1);
		sleep(1);
		i++;
 	}
	
 exit(0);
}











