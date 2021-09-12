#include <stdio.h>

int main()
{
    int end = 0;
    printf("Number of bytes: ");
    scanf("%i", &end);

    char *p = "\0";
    for (int i = 0;     i < end;     i++, p++) {
        printf("%c", *p);
    }

    puts("\n\nno error");
    return 0;
}