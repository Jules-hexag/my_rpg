/*
** EPITECH PROJECT, 2023
** amaurel
** File description:
** lib particle
*/

#ifndef GLOBAL_H_
    #define GLOBAL_H_

    #include "rpg.h"
    #include "linked_list.h"
    #include <stdlib.h>

linked_list_t *remove_first_node(linked_list_t *list)
{
    linked_list_t *tmp = list;

    list = list->next;
    free(tmp);
    return list;
}

linked_list_t *add_node(linked_list_t *list, void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));
    linked_list_t *head = list;

    node->data = data;
    node->next = NULL;
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = node;
    return head;
}

linked_list_t *create_list(void *data)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->data = data;
    list->next = NULL;
    return list;
}

linked_list_t *add_end_node(linked_list_t *list, void *data)
{
    if (list == NULL) {
        list = create_list(data);
        return list;
    }
    list = add_node(list, data);
    return list;
}

#endif /* !GLOBAL_H_ */
