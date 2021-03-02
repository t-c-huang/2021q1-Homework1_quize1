#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "qsort_quize1.h"
#include "random.h"
#include "qsort_non_recursive.h"


void list_make_node_t(node_t **list_head, node_t **list_tail, int num)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));

    if (!temp)
        return;
    else {
        if(*list_head)
            (*list_head)->back = temp;
        else
            *list_tail = temp;
        temp->value = num;
        temp->next = *list_head;
        *list_head = temp;
        temp = NULL;
    }
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

        node_t *list_head = NULL, *list_tail = NULL;
        
        // unsigned int seed = (unsigned int)time(NULL);
        // srandom(seed);
        uint64_t w, w_rand = (uint64_t)time(NULL);

        for (int i = 0; i < count; i++){
            // list = list_make_node_t(list, random() % 1024);
            msws(&w_rand, &w);
            list_make_node_t(&list_head, &list_tail, w_rand % 1024);
        }

        list_display(list_head);
        //quicksort(&list_head);
        quicksort_non_recursive(list_head, list_tail, count);
        list_display(list_head);

        if (!list_is_ordered(list_head))
            return EXIT_FAILURE;

        list_free(&list_head);
        return EXIT_SUCCESS;
    }