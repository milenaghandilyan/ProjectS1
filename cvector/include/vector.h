#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/**
 * Generic dynamic vector structure.
 * Stores elements of arbitrary type with automatic resizing.
 */
typedef struct {
    void *data;       // pointer to the data
    size_t size;      // number of elements currently stored
    size_t capacity;  // total allocated elements
    size_t elem_size; // size of each element
} Vector;

/**
 * Creates a new vector with given element size and initial capacity.
 *
 * Parameters:
 *   elem_size - size of each element in bytes
 *   capacity  - initial number of elements allocated
 *
 * Returns:
 *   Pointer to a newly allocated Vector, or NULL on failure.
 *
 * Time Complexity: O(1)
 */
Vector* vector_create(size_t elem_size, size_t capacity);

/**
 * Frees memory associated with the vector.
 *
 * Parameters:
 *   v - pointer to the Vector
 *
 * Time Complexity: O(1)
 */
void vector_destroy(Vector* v);

/**
 * Returns the number of elements currently stored in the vector.
 *
 * Parameters:
 *   v - pointer to the Vector
 *
 * Returns:
 *   Current size of the vector.
 *
 * Time Complexity: O(1)
 */
size_t vector_size(Vector* v);

/**
 * Returns the total capacity of the vector.
 *
 * Parameters:
 *   v - pointer to the Vector
 *
 * Returns:
 *   Maximum number of elements before resizing.
 *
 * Time Complexity: O(1)
 */
size_t vector_capacity(Vector* v);

/**
 * Appends an element to the end of the vector.
 * Resizes if necessary.
 *
 * Parameters:
 *   v    - pointer to the Vector
 *   elem - pointer to the element to add
 *
 * Time Complexity: O(1) amortized (due to occasional resizing)
 */
void vector_push_back(Vector* v, void* elem);

/**
 * Removes the last element from the vector.
 *
 * Parameters:
 *   v - pointer to the Vector
 *
 * Time Complexity: O(1)
 */
void vector_pop_back(Vector* v);

/**
 * Retrieves the element at the given index.
 *
 * Parameters:
 *   v     - pointer to the Vector
 *   index - position of the element (0-based)
 *
 * Returns:
 *   Pointer to the element at the given index.
 *
 * Time Complexity: O(1)
 */
void* vector_get(Vector* v, size_t index);

/**
 * Sets the element at the given index.
 *
 * Parameters:
 *   v     - pointer to the Vector
 *   index - position of the element (0-based)
 *   elem  - pointer to the new element value
 *
 * Time Complexity: O(1)
 */
void vector_set(Vector* v, size_t index, void* elem);

#endif
