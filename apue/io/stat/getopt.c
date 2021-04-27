#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc , char *argv[])
{
	int opt;

	while(1){
		opt = getopt(argc , argv ,"-lahi");
		if(opt == -1)
				break;
		switch (opt) {
			case 'l':
				printf("get -l...\n");
				break;
			case 'a':
				printf("get -a...\n ");
				break;
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
			case 'm':
				printf("get -m...\n");
				if(optarg != NULL)
					printf("arg:%s\n", optarg);
					break;
			case 1 :
				printf("not option argments\n");
				break;
			case '?':
				printf("i don't know\n");
				break;
			default:
				break;
	}
	}


	return 0;
}















