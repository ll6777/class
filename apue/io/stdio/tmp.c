#include<stdio.h>
#include<usistd>


int main(int argc , char *argv[])
{
	FILE *fp;
	char buf[1024] = {};
	char ch[1024] = {};
	char tmpnanme[100];
	char *filename;

	int n;
	FILE *tmpfp;
	filename = tmpnman(tmpname);

	


	if(argc < 4){
		printf("输入的指令出错 \n");
		return 1;
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		perror("fopen()");
		return 1;
	}
	n = argv[2];
	
	for(int i = 0 ; i < strlen(argv[3]) ; i++)
		fwrite(ch , argv[3]+i ; 1);



	
	

	return 0;
}












