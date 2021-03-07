#ifndef TREE_SORT_H
#define TREE_SORT_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"


void Traverse(struct listitem *root, struct list_head *head);

void tree_sort(struct list_head *head);


#endif /* TREE_SORT_H */