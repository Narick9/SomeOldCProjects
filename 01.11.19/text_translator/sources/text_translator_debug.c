#include <stdio.h>
#include <stdlib.h>

int size_str(const char* s)
{
    if (*s)
        return 1 + size_str(s++);
    return 1;
}

void reverse(char c[], size_t size)
{
    char buffer;
    int end = size - 2;	// нулевой символ остаётся на месте
    float half = end / (float)2;
    for (int i = 0; i < half && i < end - i; i++) {// меняем местами первый и последний символ, дальше второй и предпоследний и т.д
        buffer = c[end - i];
        c[end - i] = c[i];
        c[i] = buffer;
	}
}

void char_binchar(int n, char str[], size_t size)
{
    printf("char_binchar():\t c: %i\n", n);
    if (n < 0)
        n = 127 - n;
    printf("char_binchar():\t n: %i\n", n);
    printf("char_binchar():\t c: %c\n", n);
    char* cur = str;
    for (int i = 0; i < size - 1; i++) {	// '\0' не изменяем
        if (n) {
            if (n % 2) {
                *cur = '1';
            } else {
                *cur = '0';
            }
            n /= 2;
        } else {	// заполняем остаток нулями
            *cur = '0';
        }
        printf("char_binchar():\t iteration__(change)\t *cur: %c\t (int)*cur: %i\n", *cur, *cur);
        cur++;
        printf("char_binchar():\t new n: %i\n", n);
    }
    *cur = '\0';
    printf("char_binchar():\t *cur: %c\t (int)*cur: %i\n", *cur, *cur);

	printf("char_binchar():\t start(before reverse): %s\n", str);
	reverse(str, 9);
    printf("char_binchar():\t start(after reverse): %s\n", str);

	char* b = str;
    for (int i = 0; i < 9; i++) {
        printf("char_binchar():\t iteration__\t *b: %c\t (int)*b: %i\n", *b, *b);
        b++;
    }

    return str;
}

int main()
{
    char c;
    char str[9];
    int active = 1;
    while (active) {
        printf("main():\t iteration___\n");

		printf("main():\t your char: ");
        c = getchar();
        switch (c) {
        case ' ':
            printf("main():\t case ' ': break\n");
            //printf(" ");
            break;
        case '\n':
            printf("main():\t case '\\n': break\n");
            //printf("\n");
            break;
        case '\t':
            printf("main():\t case '%\\t': break\n");
            //printf("\t");
            break;
        case EOF:
            printf("main():\t case EOF: activ = 0; break\n");
            active = 0;
            break;
        default:
            char_binchar(c, str, 9);
            printf("main():\t ans(after char_binchar): %s\n", str);
        }
    }

    system("pause");
    return 0;
}