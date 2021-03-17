#include<stdio.h>
#include<string.h>

int main(int argc , char* argv[])
{
	FILE *fp;
	int  ch;
	int cnt;
	char buf[10] = {};
	if(argc < 2){
		return 1;
	}

	fp = fopen(argv[1] , "r");
	if(fp ==NULL){
		perror("fopen()");
		return 1;
	}
/*
	while(1){
		ch = fgetc(fp);
		if(ch == EOF){
			if(feof(fp))
				break;
			else
				goto ERROR;
		}
	}
	fputc(ch,stdout);
 */
/*	while(1) {
		memset(buf , '\0' , 10);
		if(fgets(buf , 10 , fp) == NULL){
			if(feof(fp))
				break;
			goto ERROR;
		}
		fputs(buf , stdout);
	}*/
	while(1){
		memset(buf , '\0' , 10);
		cnt = fread(buf , 1 , 10 ,fp);
		fwrite(buf ,1 , cnt , stdout);

	}
	


	fclose(fp);

	return 0;

ERROR:
	fclose(fp);
	return 1;


}












