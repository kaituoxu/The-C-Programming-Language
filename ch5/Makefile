CC = gcc
CCFLAGS = -I ../ 

ex5-2: ex5-2.c ../ch4/getch.o
	#$(CC) $(CCFLAGS) -MM $< -MT $@ > 5.2.d
	$(CC) $(CCFLAGS) $^ 

-include *.d

.PHONY: clean

clean:
	rm -f *.out
	rm -f 5.2
	rm -f *.d
