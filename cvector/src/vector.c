#include "vector.h"
#include <string.h>
#include <stdio.h>

// Internal function to resize
static void vector_resize(Vector* v, size_t new_capacity) {
    v->data = realloc(v->data, new_capacity * v->elem_size);
    v->capacity = new_capacity;
}

// Create vector
Vector* vector_create(size_t elem_size, size_t capacity) {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->elem_size = elem_size;
    v->size = 0;
    v->capacity = capacity > 0 ? capacity : 1;
    v->data = malloc(v->capacity * elem_size);
    return v;
}

// Destroy vector
void vector_destroy(Vector* v) {
    free(v->data);
    free(v);
}

// Get size
size_t vector_size(Vector* v) {
    return v->size;
}

// Get capacity
size_t vector_capacity(Vector* v) {
    return v->capacity;
}

// Add element
void vector_push_back(Vector* v, void* elem) {
    if (v->size == v->capacity)
        vector_resize(v, v->capacity * 2);
    memcpy((char*)v->data + v->size * v->elem_size, elem, v->elem_size);
    v->size++;
}

// Remove last element
void vector_pop_back(Vector* v) {
    if (v->size > 0)
        v->size--;
}

// Get element
void* vector_get(Vector* v, size_t index) {
    if (index >= v->size) return NULL;
    return (char*)v->data + index * v->elem_size;
}

// Set element
void vector_set(Vector* v, size_t index, void* elem) {
    if (index >= v->size) return;
    memcpy((char*)v->data + index * v->elem_size, elem, v->elem_size);
}
