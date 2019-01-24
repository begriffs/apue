#include "helper.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void peace(const char *s, ...)
{
	va_list args;
   
	va_start(args, s);
	vfprintf(stderr, s, args);

	va_end(args);
	exit(EXIT_FAILURE);
}
