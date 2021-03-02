#include "linked_list.h"

typedef struct label LABLE;

struct label
{
    int index;
    node_t *node_ptr;
    LABLE *label_ptr;
};
void swap_fuction(node_t *small, node_t *large);

void quicksort_non_recursive(node_t *list_head, node_t *list_tail, int count);
