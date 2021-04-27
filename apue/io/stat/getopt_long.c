#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<getopt.h>

int main(int argc , char *argv[])
{
	struct option opts[] = {
		{"help", no_argument, NULL,'p'},
		{"test",optional_argument,NULL,'t'},
		{0,0,0,0}
	};
	int c;
	while(1){
		c = getopt_long(argc,argv,"hl",opts, NULL);
		if(c == -1)
			break;
		switch(c){
				case 'h':
					printf("get -h...\n");
					break;
				case 'i':
					printf("get -i...\n");
					if (optarg != NULL) {	
							printf("arg:%s\n", optarg);
					} else
						fprintf(stderr, "required arguments\n");
						break;
				case 'l':
					printf("get -l...\n");
					break;
				case 'a':
					printf("get -a...\n ");
					break;
				case 'p':
					printf("help\n");
					break;
				case 't':
					printf("get test\n");
					if(optarg != NULL)
						puts(optarg);
					break;
				case '?':
					printf("i don't  know\n");
					break;
				default:
					break;
		}


	}






	return 0;
}







