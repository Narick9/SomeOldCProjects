#include <stdio.h>

#define HR for


int* getIt()
{
    int num;
    return &num;
}

int main()
{
    printf("we have %i", getIt());

    return 0;
}