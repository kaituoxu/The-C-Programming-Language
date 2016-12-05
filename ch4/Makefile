FILE = ex4-8
SOURCES = getop.c getch.c stack.c
OBJS = getop.o getch.o stack.o

$(FILE): $(FILE).c $(OBJS)
	gcc $(FILE).c $(OBJS)

ex4-3: ex4-3.c getop.c getch.c stack.c
	gcc ex4-3.c getop.c getch.c stack.c

4.3: 4.3.c $(OBJS)
	gcc 4.3.c $(SOURCES)

utils: utils.o
	gcc -c utils.c
