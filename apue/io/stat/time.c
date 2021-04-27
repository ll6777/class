#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int argc , char * argv[])
{
	char buf[100] = {};
	time_t t;
	time(&t);
	
	struct tm *time;
	time = localtime(&t);
	time->tm_mday  += atoi(argv[1]);

	t = mktime(time);

	time = localtime(&t);
	strftime(buf , 100 , "%Y年  %m月  %d  %H:%M:%S" , time);

	printf("%s\n" , buf);





	return 0;
}






