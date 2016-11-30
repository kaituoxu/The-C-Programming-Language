I write some util functions into utils.c and utils.h.

Generate object file by
```bash
gcc -c utils.c
# Generate utils.o
```

Link it with program, e.g.:
```bash
gcc 4.2.c utils.o
```

If you get an error like:
	对‘pow’未定义的引用
Solved it by:
```bash
gcc ex4-2.c utils.o -lm
```
