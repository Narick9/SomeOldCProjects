#include <stdio.h>
#include <string.h>

int NUMS_ADS = 7;
char *ADS[] = {
    "William: sport, eat",
    "Metthew: ns, picters, theater",
    "Luis: theater",
    "Mike: sport, Bieber",
    "Peter: gym, picters",
    "Josh: sport, theater",
    "Jed: theater, eat",
};

int sports_no_bieber(char *s)
{
    return strstr(s, "sport") && !strstr(s, "Bieber");
}

int sports_or_workout(char *s)
{
    return strstr(s, "sport") || strstr(s, "gym");
}

int ns_theater(char *s)
{
    return strstr(s, "ns") && strstr(s, "theater");
}

int arts_theater_or_dining(char *s)
{
    return strstr(s, "picters") || strstr(s, "theater") || strstr(s, "eat");
}

void find(int (*match)(char*))
{
    int i;
    puts("Search result:");
    puts("------------------------");
    for (i = 0; i < NUMS_ADS; i++) {
        if (match(ADS[i]))
            printf("%s\n", ADS[i]);
    }
    puts("------------------------");
}

int main()
{
    find(sports_no_bieber);
    find(sports_or_workout);
    find(ns_theater);
    find(arts_theater_or_dining);
    return 0;
}