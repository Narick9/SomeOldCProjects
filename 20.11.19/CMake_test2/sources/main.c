#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"

int main()
{
    puts("main.exe: Luck!");
    print_msg("mylib.a: Luck!");
    
    system("pause");
    return 0;
}