static void tree_sort_plus(struct list_head *head)
{
    if (list_empty(head) || list_is_singular(head))
        return;

    struct listitem *root, *current;
    struct listitem *min, *max;
    struct listitem *item = NULL, *is = NULL;

    root = list_first_entry(head, struct listitem, list);
    min = root;
    max = root;

    list_del(&root->list);
    INIT_LIST_HEAD(&root->list);

    list_for_each_entry_safe (item, is, head, list) {
        list_del(&item->list);
        
        if (cmpint(&item->i, &min->i) <= 0) {
            min->list.prev = &item->list;
            INIT_LIST_HEAD(&item->list);

        } else if (cmpint(&item->i, &max->i) >= 0) {
            max->list.next = &item->list;
            INIT_LIST_HEAD(&item->list);
        } else {
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
    }
    /* there are two ways of traverse can choose 8 */
    // Traverse(root, head);
    Traverse_non_recursive(root, head);
}
