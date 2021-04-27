#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>


char  leixing(const struct stat res)//文件类型
{
if((res.st_mode &  S_IFMT) == S_IFREG)
			return '-';
	else if((res.st_mode &  S_IFMT) == S_IFDIR)
			return  'd';
	else if((res.st_mode &  S_IFMT) == S_IFBLK)
			return  'b';
	else if((res.st_mode &  S_IFMT) == S_IFCHR)
			return  'c';
	else if((res.st_mode &  S_IFMT) == S_IFIFO)
			return  'P';
	else if((res.st_mode &  S_IFMT) == S_IFLNK)
			return  'l';
	else if((res.st_mode &  S_IFMT) == S_IFSOCK)
			return  's';
}
static char  *zhu(const struct stat  res)//所属主权限
{
	static char arr[10] = {'\0'};
	if(res.st_mode  & S_IRUSR)
			arr[0] = 'r';
	else
			arr[0] = '-';

	if(res.st_mode  &  S_IWUSR)
			arr[1] = 'w';
	else
			arr[1] = '-';

	if(res.st_mode  & S_IXUSR){
		if(res.st_mode & S_ISUID )
			arr[2] = 's';
		else
			arr[2] = 'x';
	}
	else
			arr[2] = '-';
	return arr;
}
static char  *zu(const struct stat res)//所属组权限
{
	static char brr[10] = {'\0'};
	if(res.st_mode  & S_IRGRP )
			brr[0] = 'r';
	else
			brr[0] = '-';

	if(res.st_mode  & S_IWGRP )
			brr[1] ='w';
	else
			brr[1] = '-';

	if(res.st_mode  & S_IXGRP )
			brr[2] = 'x';
	else
			brr[2] = '-';
	return brr;
}
static char *qita(const struct stat res)//其他用户权限
{
	static char crr[10] = {'\0'};
	if(res.st_mode  & S_IROTH )
			crr[0] = 'r';
	else
			crr[0] = '-';

	if(res.st_mode  & S_IWOTH )
			crr[1] = 'w';
	else
			crr[1] = '-';

	if(res.st_mode  & S_IXOTH )
			crr[2] = 'x';
	else
			crr[2] = '-';
	return crr;
}

static long  yinglianjie(const struct stat  res)//硬链接个数
{
	return  res.st_nlink;
}

static char *username( const struct stat res)//所属主名字
{
	struct passwd *p;
	p = getpwuid(res.st_uid);
	return  p->pw_name;
}

char *groupname( const struct stat res)//所属组名字
{
	struct group *p;
	p = getgrgid(res.st_gid);
	return  p->gr_name;
}
static long size(const struct stat res)//字节大小
{
	return res.st_size;

}

int main(int argc , char *argv[])
{
	struct stat res;


	if(argc  <  2){
		printf("输入缺少所要查看的文件\n");
		return 1;
	}

	if(stat(argv[1] , &res) == -1){
		perror("stat()");
		return 1;
	}

	printf("%c" , leixing(res));
	printf("%s" , zhu(res));
	printf("%s" , zu(res));
	printf("%s" , qita(res));
	printf(" %ld " , yinglianjie(res));
	printf(" %s " , username(res));
	printf(" %s " , groupname(res));
	printf(" %ld " , size(res));


	return 0;
}


	

