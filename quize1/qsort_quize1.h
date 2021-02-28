#ifndef QSORT_QUIZE1_H
#define QSORT_QUIZE1_H

#include<stdio.h>

#include "linked_list.h"

static inline void list_add_node_t(node_t **list, node_t *node_t);

static inline void list_concat(node_t **left, node_t *right);

void quicksort(node_t **list);

#endif /*QSORT_QUIZE1_H*/