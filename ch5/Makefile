CC = gcc
CCFLAGS = -I ../ 

SOURCES = ex5-14.c line-io.c
ex5-14: $(SOURCES)
	$(CC) $^

SOURCES = 5.11.c line-io.c
5.11: $(SOURCES)
	$(CC) $^

SOURCES = ex5-10.c getop.c getch.c stack.c
ex5-10: $(SOURCES)
	$(CC) $^

5.10.3: 5.10.3.c utils.o
	$(CC) $^

5.10.2: 5.10.2.c utils.o
	$(CC) $^

5.6: 5.6.c utils.o
	$(CC) $^

ex5-2: ex5-2.c ../ch4/getch.o
	#$(CC) $(CCFLAGS) -MM $< -MT $@ > 5.2.d
	$(CC) $(CCFLAGS) $^ 

-include *.d

.PHONY: clean

clean:
	rm -f *.out
	rm -f *.d
