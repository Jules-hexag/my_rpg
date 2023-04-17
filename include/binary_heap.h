/*
** EPITECH PROJECT, 2023
** dante
** File description:
** binary_heap.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

enum bh_type {
    BH_MAX,
    BH_MIN
};

typedef struct {
    size_t max_size;
    size_t heap_size;
    enum bh_type type;
    void **arr;
    int (*value)(void *const a);
} binary_heap;

void bh_append(binary_heap *tree, void *val);
binary_heap *bh_create(size_t max_elm, enum bh_type type,
    int (*value)(void *const elm));
void *bh_pop(binary_heap *tree);
void bh_free(binary_heap *heap);
