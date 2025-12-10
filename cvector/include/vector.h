#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

// Generic vector structure
typedef struct {
    void *data;       // pointer to the data
    size_t size;      // number of elements currently stored
    size_t capacity;  // total allocated elements
    size_t elem_size; // size of each element
} Vector;

// Create and destroy
Vector* vector_create(size_t elem_size, size_t capacity);
void vector_destroy(Vector* v);

// Get size and capacity
size_t vector_size(Vector* v);
size_t vector_capacity(Vector* v);

// Add/remove elements
void vector_push_back(Vector* v, void* elem);
void vector_pop_back(Vector* v);

// Get/set element
void* vector_get(Vector* v, size_t index);
void vector_set(Vector* v, size_t index, void* elem);

#endif
