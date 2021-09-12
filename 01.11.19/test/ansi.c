#include <stdio.h>
#include <stdlib.h>

void chrShow(char** matrix, int _x, int _y)
{
    for (int x = 0; x < _x; x++) {
        for (int y = 0; y < _y; y++)
            printf("&matrix[x][y]:\t %p\t matrix[x][y]:\t %c\n", &matrix[x][y], matrix[x][y]);
        puts("");
    }
}

int main()
{
    size_t chrMatrix = (size_t)malloc(sizeof(size_t) * 2);

    printf("chrMatrix:\t %p\n", chrMatrix);
    printf("(size_t*)chrMatrix:\t %p\n", (size_t*)chrMatrix);
    puts("");

    printf("&(size_t*)chrMatrix[0]:\t %p", &((size_t*)chrMatrix)[0]);
    puts("");

    for (int i = 0; i < 2; i++)
        printf("&((size_t*)chrMatrix)[%i]:\t %p\n", i, &((size_t*)chrMatrix)[i]);
    puts("");

    for (int line = 0; line < 2; line++) {
        ((size_t*)chrMatrix)[line] = (size_t)malloc(sizeof(char) * 3);
        for (int i = 0; i < 3; i++)
            printf("&((char*)((size_t*)chrMatrix)[line])[i]:\t %p\n", line, i, &((char*)((size_t*)chrMatrix)[line])[i]);
        puts("");
        ((char*)((size_t*)chrMatrix)[line])[0] = 'm';
        ((char*)((size_t*)chrMatrix)[line])[1] = 'u';
        ((char*)((size_t*)chrMatrix)[line])[2] = '\0';
    }
    printf("((size_t*)chrMatrix)[0]: %p\n", ((size_t*)chrMatrix)[0]);
    chrShow((char**)chrMatrix, 2, 3);

    puts("Luck!");
    return 0;
}