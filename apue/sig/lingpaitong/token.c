#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "token.h"

#define TKSIZE 1024

bool flag = false;

static token_t *tok[TKSIZE];

static void alarm_handler(int s)
{
	alarm(1);
	for(int td = 0; td <TKSIZE; td++){
			if(tok[td] != NULL){
					tok[td]->token += tok[td]->cps;
					if(tok[td]->token > tok[td]->burst)
							tok[td]->token > tok[td]->burst;
			}
	}
}

int token_init(int cps, int burst)  //初始化
{
	int td;
	for(td = 0; td<TKSIZE; td++){
			if(tok[td] == NULL){
					tok[td] = malloc(sizeof(token_t));
					if(tok[td] == NULL)
							return -1;
					tok[td]->cps = cps;
					tok[td]->burst = burst;
					tok[td]->token = 0;
					if(flag == false){
							flag = true;
							signal(SIGALRM, alarm_handler);
							alarm(1);
					}
					break;
			}

	}
	return td;
}

int token_fetct(int td, int tokens)
{
	while(tok[td]->token == 0)
			pause();
	if(tokens > tok[td]->token){
			return tok[td]->token;
			tok[td]->token = 0;
	}
	else
		tok[td]->token -= tokens;
	return tokens;
}

void(token_destroy(int td))//销毁
{
	free(tok[td]);
	tok[td] = NULL;
}

void(token_destry_all(void))
{
	int i;
	for(i = 0 ; i < TKSIZE ; i++){
		free(tok[i]);
		tok[i] = NULL;
	}
}



































