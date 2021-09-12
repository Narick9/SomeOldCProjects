#include <stdio.h>
#include <time.h>

static int my_birthday_day = 06072003;

int counter() 
{
    static int count = 0;
    return ++count;
}

int main()
{
    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#1 Operators");
    {
        puts("------------------------------------------");
        puts("Increments & Dicrements\n");
        {
            int i = 0;
            printf("i: %i\n", i);
            puts("");

            printf("i++: %i\n", i++);
            printf("i: %i\n", i);
            puts("");

            printf("++i: %i\n", ++i);
            printf("i: %i\n", i);
            puts("");

            int j = 5;
            printf("j: %i\n", j);
            puts("");

            printf("j--: %i\n", j--);
            printf("j: %i\n", j);
            puts("");

            printf("--j: %i\n", --j);
            printf("j: %i\n", j);
            puts("");
        }

        puts("------------------------------------------");
        puts("Ternor operator\n");
        {
            int x = 2;
            printf("x: %i\n", x);
            puts("");

            int m = (x == 2) ? 1 : 0;
            puts("m = (x == 2) ? 1 : 0");
            printf("m: %i\n", m);
            puts("");

            m = (x == 1) ? 5 : 10;
            puts("m = (x == 1) ? 5 : 10");
            printf("m: %i\n", m);
            puts("");
        }

        puts("------------------------------------------");
        puts("Bit operations\n");
        {
            int b = 15;
            printf("b: %i\n", b);
            puts("");

            printf("~b: %i\n", ~b);
            puts("");

            int c = 20;
            printf("c: %i\n", c);
            puts("");

            printf("b & c: %i\n", b & c);
            puts("");

            printf("b | c: %i\n", b | c);
            puts("");

            printf("b^c: %i\n", b^c);
            puts("");

            printf("b<<2: %i\n", b<<2);
            puts("");

            printf("b>>2: %i\n", b>>2);
            puts("");
        }

        puts("------------------------------------------");
        puts("Comma for separate expression\n");
        {
            puts("for (int i = 0, j = 5;    i <= 10;     i++, j++)");
            for (int i = 0, j = 5;      i <= 10;     i++, j++)
                printf("i: %i\tj: %i\n", i, j);
        }
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#2 Preprocessor directives");
    {
        puts("------------------------------------------");
        puts("The preprocessor directives\n");
        {
            puts("include <errno.h>");
            #include <errno.h>
            puts("");

            printf("errno: %ui\n", errno);
            puts("");
        }

        puts("------------------------------------------");
        puts("Macros\n");
        {
            puts("#define PRINT_MUSYA (printf(\"Musya\"))");
            #define PRINT_MUSYA (printf("Musya"))
            puts("");

            printf("PRINT_MUSYA: ");
            PRINT_MUSYA;
            puts("\n");
        }

        puts("------------------------------------------");
        puts("Conditions\n");
        {
            puts("#define TRUE (1)");
            #define TRUE (1)
            puts("");

            puts("ifdef TRUE");
            #ifdef TRUE
            printf("macro TRUE is defined\tTRUE: %i\n", TRUE);
            #else
            puts("macro TRUE is indefined");
            #endif
            puts("");
        }
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#3 Keyword static");
    {
        puts("------------------------------------------");
        puts("In a function\n");
        {
            printf("counter(): %i\n", counter());
            printf("counter(): %i\n", counter());
            printf("counter(): %i\n", counter());
            puts("");
        }

        puts("------------------------------------------");
        puts("In a global scope\n");
        {
            printf("my_birthday_day: %i\n", my_birthday_day);
            puts("");
        }
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#4 Size determination");
    {
        puts("------------------------------------------");

        puts("include <limits.h>");
        #include <limits.h>
        puts("");

        printf("int takes up %I64u bytes\n", sizeof(int));
        printf("INT_MIN: %i\tINT_MAX: %i\n", INT_MIN, INT_MAX);
        printf("SHRTMIN: %i\tSHRT_MAX: %i\n", SHRT_MIN, SHRT_MAX);
        puts("");
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#5 Automated testing");
    {
        puts("------------------------------------------");
        puts("");
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#6 GCC");
    {
        puts("------------------------------------------");
        puts("Optimization\n");
        {
            puts("test start");
            clock_t start = clock();
            double i;
            for (i = 1; i < 1000*1000; i += 0.001);
            printf("i: %lf\n", i);
            printf("test end. Spent clocks: %li\n", clock() - start);
            puts("");
        }
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#7 make");
    {
        puts("------------------------------------------");
        puts("");
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#8 Development tools (compilers)");
    {
        puts("------------------------------------------");
        puts("");
    }

    puts("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    puts("#9 Creating GUI");
    {
        puts("------------------------------------------");
        puts("");
    }

    return 0;
}