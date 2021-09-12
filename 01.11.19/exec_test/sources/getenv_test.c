#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("'%s'\n", getenv("EXTRA"));
    printf("null: '%c'\n", 0);

    puts("end - getenv");
    return 0;
}