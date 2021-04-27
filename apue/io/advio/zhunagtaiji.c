#include<stdio.h>

enum{
	STATE_R;
	STATE_W;
	STATE_ERR;
	STATE_T;
};


struct relay_st{
	int rfd;
	int wfd;
	char buf[BUFSIZE] = {};
	int readcnt;
	char *errmsg;
};

void relay_read()
{


}
void relay_write()
{


}
void relay_err()
{


}
void relay_t()
{


}



int relay_drive(struct relay_st *r)
{
	switch(r->state){
		case STATE_R:

			break;
		case STATE_W:

			break;
		case STATE_ERR:

			break;
		case STATE_T:

			break;
		defult:
			break;





	}




}






