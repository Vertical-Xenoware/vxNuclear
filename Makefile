
cc=gcc
flags=-Wall -g

program: main.c VXAtom.c
	$(cc) $(flags) $? -o $@.out -lm
