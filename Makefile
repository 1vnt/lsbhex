CFLAGS = -O3

lsbhex: main.o
	gcc -o $@ $< 
