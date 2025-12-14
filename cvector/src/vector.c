#include "vector.h"
#include <string.h>
#include <stdio.h>

// Internal function to resize the vector.
// Time Complexity: O(n) (copies all elements to new memory)
static void vector_resize(Vector* v, size_t new_capacity) {
    v->data = realloc(v->data, new_capacity * v->elem_size);
    v->capacity = new_capacity;
}

/**
 * Creates a new vector with given element size and initial capacity.
 * Time Complexity: O(1)
 */
Vector* vector_create(size_t elem_size, size_t capacity) {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->elem_size = elem_size;
    v->size = 0;
    v->capacity = capacity > 0 ? capacity : 1;
    v->data = malloc(v->capacity * elem_size);
    return v;
}

/**
 * Frees memory associated with the vector.
 * Time Complexity: O(1)
 */
void vector_destroy(Vector* v) {
    free(v->data);
    free(v);
}

/**
 * Returns the number of elements currently stored.
 * Time Complexity: O(1)
 */
size_t vector_size(Vector* v) {
    return v->size;
}

/**
 * Returns the total capacity of the vector.
 * Time Complexity: O(1)
 */
size_t vector_capacity(Vector* v) {
    return v->capacity;
}

/**
 * Appends an element to the end of the vector.
 * Resizes if necessary.
 * Time Complexity: O(1) amortized
 */
void vector_push_back(Vector* v, void* elem) {
    if (v->size == v->capacity)
        vector_resize(v, v->capacity * 2);
    memcpy((char*)v->data + v->size * v->elem_size, elem, v->elem_size);
    v->size++;
}

/**
 * Removes the last element from the vector.
 * Time Complexity: O(1)
 */
void vector_pop_back(Vector* v) {
    if (v->size > 0)
        v->size--;
}

/**
 * Retrieves the element at the given index.
 * Returns NULL if index is invalid.
 * Time Complexity: O(1)
 */
void* vector_get(Vector* v, size_t index) {
    if (index >= v->size) return NULL;
    return (char*)v->data + index * v->elem_size;
}

/**
 * Sets the element at the given index.
 * Does nothing if index is invalid.
 * Time Complexity: O(1)
 */
void vector_set(Vector* v, size_t index, void* elem) {
    if (index >= v->size) return;
    memcpy((char*)v->data + index * v->elem_size, elem, v->elem_size);
}
