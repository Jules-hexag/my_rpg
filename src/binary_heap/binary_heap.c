/*
** EPITECH PROJECT, 2023
** dante
** File description:
** binary_heap.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "binary_heap.h"

static void percolate_up(binary_heap *tree, size_t node)
{
    if (node == 0)
        return;
    size_t parent = (node - 1) / 2;
    if ((tree->type == BH_MIN
        && tree->value(tree->arr[node]) > tree->value(tree->arr[parent]))
        || (tree->type == BH_MAX
        && tree->value(tree->arr[node]) < tree->value(tree->arr[parent])))
        return;
    void *tmp = tree->arr[node];
    tree->arr[node] = tree->arr[parent];
    tree->arr[parent] = tmp;
    percolate_up(tree, parent);
}

void bh_append(binary_heap *tree, void *val)
{
    if (val == NULL)
        return;
    if (tree->heap_size == tree->max_size)
        return;
    tree->arr[tree->heap_size++] = val;
    percolate_up(tree, tree->heap_size - 1);
}

/**
 * s veut dire small, r c’est le fils droit, l le fils gauche voila
 * ya pas à être histérique
 * @param tree
 * @param i
 */
static void percolate_down(binary_heap *tree, size_t i)
{
    size_t l = i * 2 + 1;
    size_t r = i * 2 + 2;
    size_t s = i;
    if (l < tree->heap_size && ((tree->type == BH_MIN
        && tree->value(tree->arr[l]) < tree->value(tree->arr[i])) || (tree->type
        == BH_MAX && tree->value(tree->arr[l]) > tree->value(tree->arr[i]))))
        s = l;
    if (r < tree->heap_size && ((tree->type == BH_MIN
        && tree->value(tree->arr[r]) < tree->value(tree->arr[s])) || (tree->type
        == BH_MAX && tree->value(tree->arr[r]) > tree->value(tree->arr[s]))))
        s = r;
    if (s != i) {
        void *tmp = tree->arr[i];
        tree->arr[i] = tree->arr[s];
        tree->arr[s] = tmp;
        percolate_down(tree, s);
    }
}

void *bh_pop(binary_heap *tree)
{
    if (tree->heap_size <= 0)
        return NULL;
    if (tree->heap_size == 1)
        return tree->arr[--tree->heap_size];
    void *out = tree->arr[0];
    tree->arr[0] = tree->arr[--tree->heap_size];
    percolate_down(tree, 0);
    return out;
}
