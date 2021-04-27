#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<glob.h>
#include<errno.h>
#include<string.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

#define ELSE else printf("-");
#define SIZE 100

static void show(char *str, int flag);
static void myGetopt(int argc, char **argv);
static glob_t my_ls(char *path, glob_t myglob);
static void myFileType(const struct stat p);
static void myFilePm(const struct stat arr);
static void myFileHardlink(const struct stat p);
static void myFlieUsername(const struct stat p);
static void myFlieGroupname(const struct stat p);
static void myFileSize(const struct stat p);
static void myFileTime(const struct stat p);
static void _my_l(const struct stat p);
static void myFileIno(const struct stat p);
static glob_t my_a(char *arr, glob_t myglob);
static void _my_l(const struct stat p)
{
	myFileType(p);
	myFilePm(p);
	myFileHardlink(p);
	myFlieUsername(p);
	myFlieGroupname(p);
	myFileSize(p);
	myFileTime(p);
}
int main(int argc, char **argv)
{
	int myflag = 0b0000;

	int key;

	char *str = malloc(sizeof("./"));
	char *str2;
	str = "./";

	while(1)
	{
		key = getopt(argc, argv, "-lia");
		if(key == -1)
			break;

		switch(key)
		{
			case 'l':myflag |= 0b0001;break;
			case 'i':myflag |= 0b0010;break;
			case 'a':myflag |= 0b0100;break;
			case 1:  myflag |= 0b1000;
					 puts(optarg);
					 str2 = malloc(sizeof(optarg));
					 strcpy(str2, optarg);
					 break;
		}
	}
	if(myflag & 0b1000)
	{
		show(str2, myflag);
	}
	else
		show(str, myflag);
}


static void myFileType(const struct stat p)
{
	switch (p.st_mode & S_IFMT) {
		case S_IFBLK:  printf(" b"); break;
		case S_IFCHR:  printf(" c"); break;
		case S_IFDIR:  printf(" d"); break;
		case S_IFIFO:  printf(" f"); break;
		case S_IFLNK:  printf(" s"); break;
		case S_IFREG:  printf(" -"); break;
		case S_IFSOCK: printf(" s"); break;
		default:       printf(" ?"); break;

		return;
	}
}

static void myFilePm(const struct stat arr)
{
	if((arr.st_mode & S_IRUSR))
		putchar('r');
	ELSE
	if((arr.st_mode & S_IWUSR))
		putchar('w');
	ELSE
	if((arr.st_mode & S_IXUSR))	
	{
		putchar('x');
		
		if((arr.st_mode & S_ISUID))
			putchar('s');
		ELSE
	}
	ELSE
	if((arr.st_mode & S_IRGRP))
		putchar('r');
	ELSE
	if((arr.st_mode & S_IWGRP))
		putchar('w');
	ELSE
	if((arr.st_mode & S_IXGRP))
	{
		putchar('x');
		
		if(arr.st_mode & S_ISGID)
			putchar('s');
		ELSE
	}
	ELSE	
	if((arr.st_mode & S_IROTH))
		putchar('r');
}
static void myFileHardlink(const struct stat p)
{
	 printf(" %ld " , p.st_nlink);
	 return;
}

static void myFlieUsername(const struct stat p)
{
	struct passwd *arr;
	arr = getpwuid(p.st_uid);
	printf("%s ", arr->pw_name);
}
static void myFlieGroupname(const struct stat p)
{
	struct group *arr;
	arr = getgrgid(p.st_gid);
	printf("%s ", arr->gr_name);
	return;
}
static void myFileSize(const struct stat p)
{
	printf(" %ld ", p.st_size);
	return ;
}
static void myFileTime(const struct stat p)
{
	struct tm *buf;
	char arr[SIZE];

	buf = localtime(&p.st_mtime);

	strftime(arr, SIZE, "%m月 %d  %H:%M", buf);

	printf("%s  ", arr);
}
static void myFileIno(const struct stat p)
{
	printf("%ld ", p.st_ino);
}
static glob_t my_ls(char *path, glob_t myglob)
{
	char *str = malloc(sizeof(path) + 1);
	strcpy(str, path);
	strcat(str, "*");
	glob(str, 0, NULL, &myglob);
	free(str);
	str = NULL;
	return myglob;
}
static glob_t my_a(char *path, glob_t myglob)
{
	char *str = malloc(sizeof(path) + 2);
	strcpy(str, path);
	strcat(str, ".*");
	glob("./.*", GLOB_APPEND, NULL, &myglob);
	free(str);
	str =NULL;
	return myglob;
}
static void show(char *str, int flag)
{	
	glob_t myglob;
	struct stat p;
	myglob = my_ls(str, myglob);
	if(flag & 0b0100)
		myglob = my_a(str,myglob);		

	for(int i = 0; i < myglob.gl_pathc; i++)
	{	
		stat(myglob.gl_pathv[i], &p);

		if(flag & 0b0010)
			myFileIno(p);

		if(flag & 0b0001)
			_my_l(p);
		puts(myglob.gl_pathv[i] + strlen(str));
	}
	globfree(&myglob);
}

