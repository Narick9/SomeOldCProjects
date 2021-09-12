#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *question;
    struct node *no;
    struct node *yes;
} node;

int yes_no(char *question)
{
    char answer[3];
    printf("%s? (y/n): ", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

node* create(char *question)
{
    node *n = malloc(sizeof(node));
    n->question = strdup(question);
    n->no = NULL;
    n->yes = NULL;
    return n;
}

void release(node *n)
{
    if (n) {
        if (n->no)
            release(n->no);
        if (n->yes)
            release(n->yes);
        if (n->question)
            free(n->question);
        free(n);
    }
}

int main()
{
    char question[80];
    char suspect[40];
    node *start_node = create("Does the suspect wear a mustache");
    start_node->no = create("Loretta Barneschworth");
    start_node->yes = create("Ivan Lozhkin");

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("SUSPECT IS DETECTED\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                printf("Who is suspect? ");
                fgets(suspect, 40, stdin);
                current->yes = create(suspect);
                current->no = create(current->question);
                free(current->question);
                printf(
                    "Ask a question that is suitable for %s but not for %s: ",
                    suspect, current->question);
                fgets(question, 80, stdin);
                current->question = strdup(question);
                break;
            }
        }
    } while (yes_no("\nRepeat again"));
    
    release(start_node);
    return 0;
}