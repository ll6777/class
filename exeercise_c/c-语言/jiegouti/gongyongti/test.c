#include<stdio.h>
union  test_un {
	int a;
	char b;
};

int main(void)
{
	union test_un t;
	//小端存储：低字节存低地址，高字节存高地址
	//大端存储：低字节存高地址，高字节存低地址
	t.a = 0x12345678;//16进制初始化，12一个字节，34一个字节...
	printf("%#x\n",t.b);//16进制输出   小端为0x78   大端为0x12
	printf("%#x\n",t.a);
	
	int c = 0x12345678;
	char *p;
	p = (char *)(&c);


	
	printf("%#x\n",*p);









	return 0;
}




















