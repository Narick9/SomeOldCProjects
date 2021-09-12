#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void open_url(char* url)
{
	system("start https://yandex.ru/");
}

int main()
{
	open_url("https://yandex.ru/");
	return 0;
}