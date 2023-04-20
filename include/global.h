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
