#include <stdio.h>
#include <io.h>			//for dup2()
#include <unistd.h>

int main()
{
    FILE* my_file = fopen("numbers.txt", "w");
    if (dup2(fileno(my_file), 1) == -1) {
        fprintf(stderr, "Failed to redirect stdin\n");
    }
    execl("./helloworld", "./helloworld", NULL);

    system("pause");
    return 0;
}
