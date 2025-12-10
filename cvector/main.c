#include <stdio.h>
#include "include/vector.h"

int main() {
    Vector* v = vector_create(sizeof(int), 2);
    int input;

    printf("Enter integers (non-number to stop):\n");
    while (scanf("%d", &input) == 1) {
        vector_push_back(v, &input);
    }

    printf("\nYou entered %zu integers.\n", vector_size(v));
    printf("Vector capacity: %zu\n", vector_capacity(v));
    printf("Elements: ");
    for (size_t i = 0; i < vector_size(v); i++) {
        printf("%d ", *(int*)vector_get(v, i));
    }
    printf("\n");

    // Example: remove last element
    vector_pop_back(v);
    printf("\nAfter pop_back, size: %zu, elements: ", vector_size(v));
    for (size_t i = 0; i < vector_size(v); i++) {
        printf("%d ", *(int*)vector_get(v, i));
    }
    printf("\n");

    vector_destroy(v);
    return 0;
}
