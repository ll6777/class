#include<stdio.h>
#include<string.h>

#define   NAMESIZE   32   //宏定义 姓名的长度

//类型 struct  stu_st     类型名为stu_st  
struct  stu_st{
		int age;
		char name[NAMESIZE];
		float score;
		
};

int main(void)
{
	struct stu_st stu;   //未初始化
	struct stu_st stu2 = {20, "emb",100};  //初始化
	struct stu_st stu3[3] = {};
	struct stu_st *p;   //定义结构体指针
	p = stu3;

	for(int i = 0 ; i < 3 ; i++)
	{
		stu3[i].age = i+20;
//		strcpy(stu3[i].name, "aa");  姓名输入的第一种方法 
//		scanf("%s", stu3[i].name);      // 第二种
		snprintf(stu3[i].name, NAMESIZE, "hello%d", i+1);//第三种
		stu3[i].score = i+90;

	}

	printf("%d, %s, %f\n", stu2.age, stu2.name, stu2.score);

	stu.age = 19;
	strcpy(stu.name, "hello");
	stu.score = 10.9;

	printf("%d, %s, %f\n", stu.age, stu.name, stu.score);
	
	for(int j =0 ; j < 3; j++)
//		printf("%d, %s, %f\n", stu3[j].age, stu3[j].name, stu3[j].score);  //正常打印
		printf("%d, %s, %f\n", (p+j)->age, (p+j)->name, (p+j)->score);     //使用指针打印

	return 0;
}

































