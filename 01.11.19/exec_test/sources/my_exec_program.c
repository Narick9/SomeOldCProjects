#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    //char *my_env[] = {"JUICE=peach and apple", NULL};
    if (execle("diner_info", "4", NULL, my_env) == -1)
        fprintf(stderr, "Failed to run 'diner_info': %s\n", strerror(errno));
    //execl("print_world", "printf_world", NULL);
    //system("print_world");

    puts("end - my_exec_program");
    system("pause");
    return 0;
}