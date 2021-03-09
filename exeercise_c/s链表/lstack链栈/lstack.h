#ifndef __LLIST_H
#define __LLIST_H
#include "ds.h"




typedef listhead_t lstack_t;   //链栈

int lstackInit(int size, lstack_t **ls);

int lstackIsEmpty(lstack_t *ls);


int lstackPush(lstack_t *ls, const void *data);   //入栈


int lstackPop(lstack_t *ls, void *data);   //出栈


void lstackDestroy(lstack_t *ls);  //销毁




























#endif

