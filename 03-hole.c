#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char buf1[] = "abcdefghij",
	 buf2[] = "ABCDEFGHIJ";

void err_sys(const char *msg)
{
	fputs(msg, stderr);
	exit(EXIT_FAILURE);
}

int main(void)
{
	int fd;

	if ((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		err_sys("Error with creat");
	if (write(fd, buf1, sizeof(buf1)) != sizeof(buf1))
		err_sys("buf1 write error");

	if (lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error");

	if (write(fd, buf2, sizeof(buf2)) != sizeof(buf2))
		err_sys("buf2 write error");
}
