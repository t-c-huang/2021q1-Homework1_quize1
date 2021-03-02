#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct __node
{
    int value;
    struct __node *next;
    struct __node *back;
} node_t;

static bool list_is_ordered(node_t *list)
{
    bool first = true;
    int value;
    while (list)
    {
        if (first)
        {
            value = list->value;
            first = false;
        }
        else
        {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

static void list_display(node_t *list)
{
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

static void list_display_back(node_t *list)
{
    while (list)
    {
        printf("%d ", list->value);
        list = list->back;
    }
    printf("\n");
}

void list_make_node_t(node_t **list_head, node_t **list_tail, int num);

#endif /*LINKED_LIST_H*/