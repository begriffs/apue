CFLAGS = -std=c89 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -Wpedantic -Wshadow -pedantic-errors

PROGS = 03-seek 03-hole 03-flags 03-errout

all: $(PROGS)

.SUFFIXES :
.SUFFIXES : .o .c .h

$(PROGS) : helper.o

helper.o : helper.c helper.h

.c :
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) helper.o $<

watch:
	ls *.c *.h | entr ${MAKE}

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o
