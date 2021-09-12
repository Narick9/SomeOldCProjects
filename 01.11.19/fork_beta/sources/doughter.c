#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#include "my_lib.h"

void delay(const unsigned int _msc)
{
	clock_t end;
	if ( (end = clock()) == -1 )
		error_msg("Delay(): clock doesn't give me ticks");	// first time worst
	end += _msc*(CLOCKS_PER_SEC/1000);
	while (clock() < end);
}

int main()
{
	printf("start delay(%s): %li\n", getenv("DELAY"), clock());
	delay(2*1000);
	printf("end: %li\n", clock());

	return 0;
}