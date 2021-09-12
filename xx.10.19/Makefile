ecnrypt.o: encrypt.h encrypt.c
	gcc -c encrypt.h encrypt.c
checksum.o: checksum.h checksum.c
	gcc -c checksum.h checksum.o
test_code: test_code.c encrypt.o checksum.o
	gcc test_code.c encrypt.o checksum.o -o test_code