#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "qsort_non_recursive.h"
/*
 * This is the modify quick sort refering to https://alienryderflex.com/quicksort .
 * It's doing non recursive.
 */
void swap(node_t *small, node_t *large)
{
    int temp = small->value;
    small->value = large->value;
    large->value = temp;
}

void quicksort_non_recursive(node_t *list_head, node_t *list_tail, int count)
{
    #define MAX_LEVELS 1000
    LABLE left = {.node_ptr = list_head},
          right = {.node_ptr = list_tail},
            beg[MAX_LEVELS],
            end[MAX_LEVELS];
    

    int piv = 0, head = -1, tail = -1;

    beg[0].index =0;
    end[0].index = count - 1;
    beg[0].node_ptr = list_head;
    end[0].node_ptr = list_tail;
    head++;
    tail++;

    while (tail >= head) {
        
        left.index = beg[head].index;
        right.index = end[head].index;
        
        left.node_ptr = beg[head].node_ptr;
        right.node_ptr = end[head].node_ptr;

        if (left.index < right.index) {

            piv = beg[head].node_ptr->value;
            
            while (left.index < right.index) {
                
                while (right.node_ptr->value >= piv && left.index < right.index) {
                    right.index--;
                    right.node_ptr = right.node_ptr->back;
                }
                if (left.node_ptr && right.node_ptr &&
                    left.index < right.index) {
                    left.node_ptr->value = right.node_ptr->value;
                    left.node_ptr = left.node_ptr->next;
                    left.index++;
                }
                while (left.node_ptr->value <= piv && left.index < right.index) {
                    left.index++;
                    left.node_ptr = left.node_ptr->next;
                }
                if (left.node_ptr && right.node_ptr &&
                    left.index < right.index) {
                    right.node_ptr->value = left.node_ptr->value;
                    right.node_ptr = right.node_ptr->back;
                    right.index--;
                }
            }
            left.node_ptr->value = piv;

            if (beg[head].index < right.index - 1) {
                tail++;
                beg[tail].node_ptr = beg[head].node_ptr;
                end[tail].node_ptr = right.node_ptr->back;

                beg[tail].index = beg[head].index;
                end[tail].index = right.index - 1;
            }

            if (left.index + 1 < end[head].index) {
                tail++;
                beg[tail].node_ptr = left.node_ptr->next;
                end[tail].node_ptr = end[head].node_ptr;

                beg[tail].index = left.index + 1;
                end[tail].index = end[head].index;
            }
            head++;
        }
    }
}


    // while (i >= 0) {
    //     left.index = beg[i]; //begin.index;
    //     right.index = end[i] - 1; //end.index - 1;

    //     if (left.index < right.index && left.node_ptr) {
    //         pivot = left.node_ptr->value;

    //         while (left.index < right.index) {
    //             while (right.node_ptr && right.node_ptr->value >= pivot &&
    //                    left.index < right.index) {
    //                 right.node_ptr = right.node_ptr->back;
    //                 right.index--;
    //             }

    //             if (left.index < right.index && left.node_ptr) {
    //                 //arr[L++] = arr[R];
    //                 //printf("left move\n");
    //                 swap(left.node_ptr, right.node_ptr);
    //                 left.node_ptr = left.node_ptr->next;
    //                 left.index++;
    //                 //printf("\nswap1 left:%d right:%d\n", left.node_ptr->value, right.node_ptr->value);
    //             }

    //             while (left.node_ptr && left.node_ptr->value <= pivot &&
    //                    left.index < right.index) {
    //                 left.node_ptr = left.node_ptr->next;
    //                 left.index++;
    //             }

    //             if (left.index < right.index && right.node_ptr) {
    //                 //arr[R--] = arr[L];
    //                 //printf("right move\n");
    //                 swap(left.node_ptr, right.node_ptr);
    //                 right.node_ptr = right.node_ptr->back;
    //                 right.index--;
    //                 //printf("\nswap2 left:%d right:%d\n", left.node_ptr->value, right.node_ptr->value);
    //             }
    //         }
    //         // if (left.node_ptr)
    //         //     left.node_ptr->value = pivot;
    //         //begin.index
    //         beg[i + 1] = left.index + 1;
    //         //end.index
    //         end[i + 1] = end[i];
    //         end[i++] = left.index;

    //         printf("end !!!!\n");
    //         // if (end[i] - beg[i] > end[i - 1] - beg[i - 1])
    //         // {
    //         //     temp = beg[i];
    //         //     beg[i] = beg[i - 1];
    //         //     beg[i - 1] = temp;
    //         //     temp = end[i];
    //         //     end[i] = end[i - 1];
    //         //     end[i - 1] = temp;
    //         // }
    //     } else
    //         i--;
    // }
// }