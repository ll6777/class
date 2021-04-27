#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 令牌桶:速率 令牌 上限

#define BUFSIZE	10
#define CPS		BUFSIZE	
#define BURST	100

static int token = 0;

static void alrm_handler(int s)
{
	alarm(1);
	token += CPS;  //加上速率
	if (token >= BURST)  //如果达到上限
		token = BURST;  //只能是最大值
}

int main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;

	signal(SIGALRM, alrm_handler);
	alarm(1);

	if (argc < 2)
		return 1;
	do {
		fd = open(argv[1], O_RDONLY);
		if (-1 == fd) {
			// 是否为假错
			if (errno == EINTR) //如果三因为打开被打断出现的假错是需要重新进入的
				continue;
			perror("open()");
			return 1;
		}
		break; //真出现错误就退出
	} while (1);

	while (1) {
		// 流量控制
		while (token < CPS)
			pause();
		token -= CPS;
		
		memset(buf, '\0', BUFSIZE);
		while (1) {
			cnt = read(fd, buf, BUFSIZE);
			if (cnt == -1) {
				if (errno == EINTR)
					continue;
				perror("read()");
				goto ERROR;
			}
			break;
		}
		if (cnt == 0) {
			// EOF
			break;
		}
		write(1, buf, cnt);
	}

	close(fd);
	
	return 0;
ERROR:
	close(fd);
	return 1;
}

