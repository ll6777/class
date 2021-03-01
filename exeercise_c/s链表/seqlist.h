//类型定义  函数声明
//此头文件多次包含 只展开一次
#ifndef  __SEQLITE_H
#define  __SEQLITE_H

//抽象数据类型
//顺序表
typedef  struct {
		void *arr;    //存储数据的首地址
		int size;    //每一个元素所占字节个数
		int nmemb;    //结构中的成员个数
}seqlist_t;

//接口实现
seqlist_t *seqlistInit(int size);    //初始化顺序表


int seqlistInesert(seqlist_t *s, const void *data);   //增加新元素


void seqlisTraval(const  seqlist_t *s, void(*pri)(const void *data));   //遍历



#endif













