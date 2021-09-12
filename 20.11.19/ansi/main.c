#include <stdio.h>
#include <windows.h>


int main()
{
   fprintf(stdin, "hello");
   for (int i = 0; i < 256; i++)
      printf("%c ", i);
   puts("");
   
   system("pause");
   return 0;
}