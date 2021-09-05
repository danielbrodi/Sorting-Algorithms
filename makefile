#PATH
IDIR = ./api_files/
SDIR = ./source_files/
TDIR = ./test_files/

#COMPILER	
CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g -lm -I$(IDIR)
RM = rm -rf

CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g -lm -I$(IDIR)
RM = rm -rf

TARGETS := radix sorts cmp_sort

.PHONY = all clean

all: $(TARGETS)

%: $(TDIR)%_test.c $(SDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	$(RM) *.o $(TARGETS)
