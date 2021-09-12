#include <stdio.h>

int main(int argc, char **argv, char **environ){
	int i = -1;

	while (environ[++i])	// зачем так делать?
		printf("%s\n",environ[i]);
}
