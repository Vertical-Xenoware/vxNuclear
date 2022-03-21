
cc=gcc
flags=-Wall -g
target=./bin/program.out
prereqs=./obj/main.o ./obj/VXAtom.o

$(target): $(prereqs)
	$(cc) $(flags) $? -o $@ -lm

./obj/main.o: main.c
	$(cc) $(flags) -c $? -o $@ -lm

./obj/VXAtom.o: VXAtom.c
	$(cc) $(flags) -c $? -o $@ -lm