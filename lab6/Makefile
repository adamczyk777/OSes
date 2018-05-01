all: dup_example simple_pipe clean

simple_pipe: simple_pipe.c
		gcc simple_pipe.c -o simple_pipe

dup_example: dup_example.c
		gcc dup_example.c -o dup_example

.PHONY: clean

clean:
		rm -f *.o