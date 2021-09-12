#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *now()
{
    time_t t;
    time(&t);
    return asctime(localtime (&t));
}

void del_new_line(char *mes)
{
    while(*mes) {
        if (*mes == '\n')
            *mes = '_';
        mes++;
    }
}

int main()
{
    char comment[80];
    char cmd[120];

    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s: %s' >> reports.log", now(), comment);
    del_new_line(cmd);

    system(cmd);
    puts("end");
    //system("pause");
    return 0;
}