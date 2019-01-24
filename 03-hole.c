#include "helper.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

char buf1[] = "abcdefghij",
	 buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;

	if ((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		peace("Error with creat");
	if (write(fd, buf1, sizeof(buf1)) != sizeof(buf1))
		peace("buf1 write error");

	if (lseek(fd, 16384, SEEK_SET) == -1)
		peace("lseek error");

	if (write(fd, buf2, sizeof(buf2)) != sizeof(buf2))
		peace("buf2 write error");
}
