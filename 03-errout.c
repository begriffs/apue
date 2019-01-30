#include <stdio.h>

int main(void)
{
	int i;
	for (i = 0; i < 10; i++)
		fprintf(i%2 ? stdout : stderr, "%s %d\n",
				i%2 ? "out" : "err", i);
}
