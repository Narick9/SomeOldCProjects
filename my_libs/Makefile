
./libmy_lib/my_lib.o: ./libmy_lib/my_lib.c ./libmy_lib/my_lib.h
	gcc -c ./libmy_lib/my_lib.c -o ./libmy_lib/my_lib.o
libmy_lib.a: ./libmy_lib/my_lib.o
	ar -rcs libmy_lib.a ./libmy_lib/my_lib.o