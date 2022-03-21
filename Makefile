
cc=gcc
flags=-Wall -g

program: ./obj/main.o ./obj/VXAtom.o
	$(cc) $(flags) $? -o ./bin/$@.out -lm

./obj/main.o: main.c
	$(cc) $(flags) -c $? -o $@ -lm

./obj/VXAtom.o: VXAtom.c
	$(cc) $(flags) -c $? -o $@ -lm