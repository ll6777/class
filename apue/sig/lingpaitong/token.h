#ifndef __TOKEN___
#define __TOKEN__

typedef struct{
		int cps;   //速率
		int burst;  //上限
		int token;  //令牌
}token_t;

int token_init(int cps, int burst);//初始化  

int token_fetch(int td, int tokens); //取令牌


void token_destroy(int td);//销毁令牌

void token_destry_all(void);   //销毁所有令牌桶

#endif

