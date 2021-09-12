#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return -(a - b);
}

typedef struct {
    int width;
    int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
    rectangle new_a = *(rectangle*)a;
    rectangle new_b = *(rectangle*)b;
    int s_a = new_a.width*new_a.height;
    int s_b = new_b.width*new_b.height;
    return s_a - s_b;
}

int compare_names(const void* a, const void* b)
{
    char** sa = (char**)a;
    char** sb = (char**)b;
    return strcmp(*sa, *sb);
}

int compare_areas_desc(const void* a, const void* b)
{
    return -compare_areas(a, b);
}

int compare_names_desc(const void* a, const void* b)
{
    return -compare_names(a, b);
}

int main()
{
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("Sorted scores:");
    for (int i = 0; i < 7; i++) 
        printf("Score: %i\n", scores[i]);

    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char*), compare_names);
    puts("Sorted names:");
    for (int i = 0; i < 4; i++)
        printf("%s\n", names[i]);
    
    rectangle rects[] = {{.width=3, .height=2}, {.width=4, .height=1}};
    qsort(rects, 2, sizeof(rectangle), compare_areas_desc);
    puts("Sorted rectangles:");
    for (int i = 0; i < 2; i++)
        printf("%i,%i\n", rects[i].width, rects[i].height);

    return 0;
}