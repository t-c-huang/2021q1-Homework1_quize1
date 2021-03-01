#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "qsort_quize1.h"

node_t *list_make_node_t(node_t *list, int num)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));

    if (!temp)
    {
        return NULL;
    }
    else
    {
        temp->value = num;
        temp->next = list;
        list = temp;
        temp = NULL;
    }
    return list;
}

void list_free(node_t **list)
{
    if (!*list)
        return;

    node_t *temp = *list;

    while (*list)
    {
        *list = (*list)->next;
        free(temp);
        temp = *list;
    }
    free(*list);
}

    int main(int argc, char **argv)
    {
        size_t count = 20;

        node_t *list = NULL;
        
        unsigned int seed = (unsigned int)time(NULL);
        srandom(seed);
        
        while (count--)
            list = list_make_node_t(list, random() % 1024);
            
        list_display(list);
        quicksort(&list);
        list_display(list);

        if (!list_is_ordered(list))
            return EXIT_FAILURE;

        list_free(&list);
        return EXIT_SUCCESS;
    }