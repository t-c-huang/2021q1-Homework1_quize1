#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#include "common.h"

typedef struct stack_ele STACK_ELE;
struct stack_ele {
    struct list_head temp_head;
    bool merged;  // defualt false
    int level;
};

static void list_qsort_non_recursive(struct list_head *head)
{
    struct listitem *item = NULL, *is = NULL;

    struct listitem *pivot[256];
    struct stack_ele stack[256];
    int stack_top = -1, stack_bottum = -1, stack_current = -1, pivot_top = -1,
        pivot_bottum = -1, pivot_current = -1;  // 256 as ARRAY_SIZE(values)

    // Split part

    if (list_empty(head) || list_is_singular(head))
        return;

    INIT_LIST_HEAD(&stack[0].temp_head);  // list_less
    INIT_LIST_HEAD(&stack[1].temp_head);  // list_large

    stack[0].level = 1;
    stack[1].level = 1;

    pivot[0] = list_first_entry(head, struct listitem, list);
    list_del(&pivot[0]->list);

    list_for_each_entry_safe (item, is, head, list) {
        if (cmpint(&item->i, &pivot[0]->i) < 0)
            list_move_tail(&item->list, &stack[0]);
        else
            list_move(&item->list, &stack[1]);
    }

    stack_top += 2;
    stack_bottum++;
    stack_current++;
    pivot_top += 1;
    pivot_bottum++;
    // pivot_current++;

    while (stack_top >= stack_current) {
        if (!list_empty(&stack[stack_current].temp_head) &&
            !list_is_singular(&stack[stack_current].temp_head)) {
            pivot_top++;
            pivot[pivot_top] = list_first_entry(&stack[stack_current].temp_head,
                                                struct listitem, list);
            list_del(&pivot[pivot_top]->list);

            INIT_LIST_HEAD(&stack[stack_top + 1]);
            INIT_LIST_HEAD(&stack[stack_top + 2]);

            list_for_each_entry_safe (item, is, &stack[stack_current].temp_head,
                                      list) {
                if (cmpint(&item->i, &pivot[pivot_top]->i) < 0)
                    list_move_tail(&item->list,
                                   &stack[stack_top + 1].temp_head);
                else
                    list_move(&item->list, &stack[stack_top + 2].temp_head);
            }
            stack[stack_top + 1].level = stack[stack_current].level + 1;
            stack[stack_top + 2].level = stack[stack_current].level + 1;
            stack_top += 2;
        }
        stack_current++;
        // stack[stack_current].slipt = true;
        // if (!list_empty(&stack[stack_top + 1].temp_head) &&
        //     !list_is_singular(&stack[stack_top + 1].temp_head))
        //     stack[stack_top + 1].slipt = true;

        // if (!list_empty(&stack[stack_top + 2].temp_head) &&
        //     !list_is_singular(&stack[stack_top + 2].temp_head))
        //     stack[stack_top + 1].slipt = true;
    }

    int less_index, greater_index = stack_top, merge_index = stack_top - 2;
    pivot_current = pivot_top;

    while (greater_index >= stack_bottum + 1) {
        while (stack[greater_index].merged)
            greater_index--;

        less_index = greater_index - 1;
        while (stack[less_index].merged &&
               stack[less_index].level != stack[greater_index].level)
            less_index--;

        while (stack[merge_index].level != stack[less_index].level + 1)
            merge_index--;

        list_add(&pivot[pivot_current]->list, &stack[merge_index].temp_head);
        list_splice(&stack[less_index].temp_head,
                    &stack[merge_index].temp_head);
        list_splice_tail(&stack[greater_index].temp_head,
                         &stack[merge_index].temp_head);

        stack[less_index].merged = true;
        stack[greater_index].merged = true;
        pivot_current--;
    }
    list_add(&pivot[pivot_current]->list, head);
    list_splice(&stack[greater_index].temp_head, head);
    list_splice_tail(&stack[less_index].temp_head, head);
}