/*
** EPITECH PROJECT, 2023
** dante
** File description:
** binary_heap2.c
*/

#include <stdlib.h>
#include "binary_heap.h"

void bh_free(binary_heap *heap)
{
    free(heap->arr);
    free(heap);
}

binary_heap *bh_create(size_t max_elm, enum bh_type type,
    int (*value)(void *const elm))
{
    binary_heap *out = malloc(sizeof(binary_heap));
    if (out == NULL)
        return NULL;
    out->arr = malloc(sizeof(void *) * max_elm);
    if (out->arr == NULL) {
        free(out);
        return NULL;
    }
    out->type = type;
    out->max_size = max_elm;
    out->heap_size = 0;
    out->value = value;
    return out;
}
