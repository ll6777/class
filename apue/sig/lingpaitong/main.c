#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "token.h"

#define    BUFSIZE    10
#define    CPS      BUFSIZE
#define    BURST      100
#define    TOKENS     CPS

int main(int argc, char *argv[])
{
	int td;
	int fd;
	char buf[BUFSIZE]={}; 
	int cnt;
	
	td = token_init(CPS, BURST);

 	if (argc <2)
 		return 1;
 	do{
 		fd = open(argv[1],O_RDONLY); 
		if (-1 == fd){
 		if(errno = EINTR)
 			continue;
		 perror("open()");
		 return 1;
	  }
	break;

	}
	while (1){  
		int tokens = token_fetch(td, TOKENS); 
			printf("%d\n",tokens);

			memset(buf, '\0' , BUFSIZE); 
			while (1){
				 cnt = read(fd,buf,BUFSIZE); 
				 if (cnt = -1){
						 if (errno = EINTR)
						 	continue;
						 perror("read()"); 
						 goto ERROR;
				 }
				break;
				}
				if(cnt == 0)
					break;
				write(1, buf,cnt);

			 }
			close(fd);
	        token_destroy( td);
				 return 0;
ERROR:
	close(fd);
	return 1;
}
























