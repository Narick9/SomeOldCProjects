#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("\nargc: %i\n", argc);
    printf("Dinners: %s\n", argv[1]);
    printf("Juice: %s\n", getenv("JUICE"));

    puts("end - diner_info");
    return 0;
}