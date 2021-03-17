#include<stdio.h>
#include<unistd.h>

#define FLNAME  "lll.c"


int main(void)
{
	FILE *fp;
	char buf[100] = {};
	int cnt;

	fp = fopen(FLNAME , "r");
	if(fp == NULL){
		perror("fopen()");
		return 1;
	}
	fseek(fp , 10 ,SEEK_CUR);
	printf(" %ld \n" , ftell(fp));
	cnt = fread(buf ,1 ,100 , fp);
	fwrite(buf , 1 , cnt , stdout);
	fclose(fp);

	return 0;
}

















