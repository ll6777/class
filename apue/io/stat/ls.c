#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>

#define   BUFSIZE  100

int main(int argc , char *argv[])
{

	struct stat res;

	if(argc  <  2)
		return 1;
	
	if(stat(argv[1] , &res) == -1){
		perror("stat()");
		return 1;
	}
	//文件类型
	if((res.st_mode &  S_IFMT) == S_IFREG)
			putchar('-');
	else if((res.st_mode &  S_IFMT) == S_IFDIR)
			putchar('d');
	else if((res.st_mode &  S_IFMT) == S_IFBLK)
			putchar('b');
	else if((res.st_mode &  S_IFMT) == S_IFCHR)
			putchar('c');
	else if((res.st_mode &  S_IFMT) == S_IFIFO)
			putchar('P');
	else if((res.st_mode &  S_IFMT) == S_IFLNK)
			putchar('l');
	else if((res.st_mode &  S_IFMT) == S_IFSOCK)
			putchar('s');

//所属主权限
	if(res.st_mode  & S_IRUSR)
			putchar('r');
	else
			putchar('-');
	
	if(res.st_mode  &  S_IWUSR)
			putchar('w');
	else
			putchar('-');

	if(res.st_mode  & S_IXUSR){
		if(res.st_mode & S_ISUID )
			putchar('s');	
		else
			putchar('x');
	}
	else
			putchar('-');
//所属组权限
	if(res.st_mode  & S_IRGRP )
			putchar('r');
	else
			putchar('-');

	if(res.st_mode  & S_IWGRP )
			putchar('w');
	else
			putchar('-');

	if(res.st_mode  & S_IXGRP )
			putchar('x');
	else
			putchar('-');

//其他用户权限
	if(res.st_mode  & S_IROTH )
			putchar('r');
	else
			putchar('-');

	if(res.st_mode  & S_IWOTH )
			putchar('w');
	else
			putchar('-');

	if(res.st_mode  & S_IXOTH )
			putchar('x');
	else
			putchar('-');
//硬链接个数
	printf(" %ld ",  res.st_nlink);
//所属主名 所属组名
	struct passwd *p;
	p = getpwuid(res.st_uid);
	struct group *g;
	g = getgrgid(res.st_gid);
	printf("%s %s " ,p->pw_name , g->gr_name );


//字节大小
	printf("%ld  " , res.st_size);

	//时间	
	struct tm *t;
	char buf[BUFSIZE] = {};
	t = localtime(&res.st_mtime/*time_t*/);
	// if error
	strftime(buf, BUFSIZE, "%m月 %d %H:%M", t);
	printf("%s ", buf);

	printf("%s", argv[1]);

	putchar('\n');



	return 0;
}






