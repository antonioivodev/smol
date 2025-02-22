
/*
 * Copyright (c) 2024 Seu Nome ou Sua Empresa
 *
 * Permission to use, copy, modify, and distribute this software for any purpose
 * with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED.
 * See https://opensource.org/licenses/MIT-0 for full license text.
 */

#ifndef SMOL_ARRAY
#define SMOL_ARRAY

#include <stdlib.h>
#include <string.h>

typedef struct {
  void *data;
  size_t size;
  size_t capacity;
} smol_array;

smol_array smol_array_create(size_t size, size_t capacity);

void smol_array_set(smol_array *array, size_t index, void *item);

void *smol_array_get(smol_array *array, size_t index);

void smol_array_free(smol_array *array);

#ifdef SMOL_ARRAY_IMPLEMENTATION

smol_array smol_array_create(size_t size, size_t capacity) {
  smol_array array;
  array.data = malloc(size * capacity);
  array.size = size;
  array.capacity = capacity;
  return array;
}

void smol_array_set(smol_array *array, size_t index, void *item) {
  if (index >= array->capacity) {
    return;
  }
  memcpy((char *)array->data + (index * array->size), item, array->size);
}

void *smol_array_get(smol_array *array, size_t index) {
  if (index >= array->capacity) {
    return NULL;
  }
  return (char *)array->data + index * array->size;
}

void smol_array_free(smol_array *array) {
  free(array->data);
  array->data = NULL;
}

#endif /* SMOL_ARRAY_IMPLEMENTATION */

#endif /* SMOL_ARRAY */
