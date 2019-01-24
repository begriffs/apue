#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void peace(const char *s, ...)
{
	va_list args;
   
	va_start(args, s);
	vfprintf(stderr, s, args);

	va_end(args);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	int val, fd;
	char *parsed_until;

	if (argc != 2)
		peace("usage: %s <descriptor>\n", *argv);
	fd = strtol(argv[1], &parsed_until, 10);
	if (strcmp(parsed_until, "") != 0)
		peace("Unable to parse descriptor: %s\n", parsed_until);
	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
		peace("fcntl error for fd %d\n", fd);

	switch (val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("Read only");
			break;
		case O_WRONLY:
			printf("Write only");
			break;
		default:
			printf("Unknown access mode");
	}

	if (val & O_APPEND)
		printf(", append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");

	putchar('\n');
}
