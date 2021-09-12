#include <stdio.h>
#include <windows.h>
#include <time.h>

void sleeping(unsigned int _delay, unsigned int _iterationQuantity)
{
	clock_t end;
	while (_iterationQuantity) {
		end = clock() + _delay;
		while (clock() < end);	// ожидание
		puts("Delay...");		// признак жизни процесса
		_iterationQuantity--;
	}
}

int main(int argc, char* argv[])
{
	char* phrase = argv[1];

	system("child_old");
	puts("parent.exe: end");
	return 0;
}