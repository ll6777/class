//类型定义  函数声明
//此头文件多次包含 只展开一次
#ifndef  __LIST_H
#define  __LIST_H

enum {HEADINSERT, TAILINSERT};


//数据结点
typedef  struct node_st{
		void *data;    //存储数据域的首地址
		struct node_st *next;
}node_t;

//头结点
typedef struct{
		struct node_st *next;
		int size;    //每一个元素所占字节个数
		int nmemb;    //结构中的成员个数
}listhead_t;

typedef int (*cmp_t)(const void *data, const void *key);

typedef void (*pri_t)(const void *data);



//接口

int listheadInit(int size, listhead_t **l );   //初始化头结点

int listInsert(listhead_t *l, const void *data, int way);   //增加 

int listUpdate(const listhead_t *l,const void *data,cmp_t cmp, const void *newdata); //修改

int listDelete(listhead_t *l, const void *key, cmp_t cmp);  //删除

void listTraval(const listhead_t *l, pri_t pri);    //遍历

void listDestroy(listhead_t *l);    //销毁

#endif
































