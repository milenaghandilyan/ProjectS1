C-Vector: A Generic Dynamic Array Library in C
Overview
C-Vector is a generic dynamic array library for C. It provides a flexible data structure called a vector, which can store elements of any type and automatically resizes as needed. Unlike standard C arrays, which have a fixed size, C-Vector handles memory management, making it easier to store an unknown number of elements safely and efficiently.

Features
Create and destroy a vector
Get the current size and capacity
Add an element to the end (push_back)
Remove an element from the end (pop_back)
Get or set an element at a specific index(get, set)
Automatically resize the internal array when capacity is reached
How It Works
C-Vector manages an internal memory buffer. When adding more elements than the current capacity, it doubles the capacity automatically. You can access and modify elements using get and set functions, making your code cleaner and safer. Each function is documented in vector.h with descriptions and Big O notation for time complexity.

Demo Program
The included demo(main.c) program shows how to use C-Vector to read an unknown number of integers from the user:

Vector* v = vector_create(sizeof(int), 2);
int input;

printf("Enter integers (non-number to stop):\n");
while (scanf("%d", &input) == 1) {
    vector_push_back(v, &input);
}

// Print elements
for (size_t i = 0; i < vector_size(v); i++) {
    printf("%d ", *(int*)vector_get(v, i));
}
printf("\n");

// Remove last element
vector_pop_back(v);
Exampe Run

Enter integers (non-number to stop):
10
20
30
q

You entered 3 integers.
Vector capacity: 4
Elements: 10 20 30

After pop_back, size: 2, elements: 10 20
Why Use C-Vector
Handles dynamic memory automatically Reusable for any data type (int, float, structs, etc.) Reduces bugs related to manual memory management Ideal for applications where the number of elements changes dynamically

Getting started
1.Clone the repository

git clone https://github.com/NairaGal/C-Vector.git
cd cvector
2.Compile using Makefile

make
3.Run the demo

./vector_demo
Enter integers until a non-number is typed. The program will display all stored elements and the vector's size and capacity.
