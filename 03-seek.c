#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		puts("Cannot seek");
	else
		puts("Seek OK");
}
