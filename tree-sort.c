#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "list.h"
#include "tree-sort.h"

void Traverse(struct listitem *root, struct list_head *head)
{
    struct listitem *work;
    if (root->list.prev != &root->list) {
        Traverse(container_of((root->list).prev, struct listitem, list), head);
    }
    work = container_of((root->list).next, struct listitem, list);
    list_add_tail(&root->list, head);

    if (&work->list != &root->list) {
        Traverse(work, head);
    }
}


void tree_sort(struct list_head *head)
{
    if (list_empty(head) || list_is_singular(head))
        return;

    struct listitem *root, *current;
    struct listitem *item = NULL, *is = NULL;

    root = list_first_entry(head, struct listitem, list);
    list_del(&root->list);

    INIT_LIST_HEAD(&root->list);

    list_for_each_entry_safe (item, is, head, list) {
        list_del(&item->list);

        current = root;

        while (1) {
            if (cmpint(&item->i, &current->i) < 0) {
                if (current->list.prev == &current->list) {
                    current->list.prev = &item->list;
                    INIT_LIST_HEAD(&item->list);
                    break;
                } else {
                    current = container_of((current->list).prev,
                                           struct listitem, list);
                }
            } else {
                if (current->list.next == &current->list) {
                    current->list.next = &item->list;
                    INIT_LIST_HEAD(&item->list);
                    break;
                } else {
                    current = container_of((current->list).next,
                                           struct listitem, list);
                    ;
                }
            }
        }
    }
    Traverse(root, head);
}