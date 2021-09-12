#include <stdio.h>
#include <stdlib.h>

int* func()
{

}

int main()
{
    int* i;
    printf("(size_t)i: %p\n", i);
    i = func();
    printf("(size_t)i: %p\n", i);
    i = func();
    printf("(size_t)i: %p\n", i);

    system("pause");
    return 0;
}