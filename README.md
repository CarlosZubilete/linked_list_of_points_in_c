# Linked List of Points in C

This project is an interactive C program that stores two-dimensional points
in a singly linked list.

It is a study project for:

- Dynamic memory allocation
- Linked lists and nodes
- Pointers and double pointers
- Function pointers
- Quicksort
- Basic geometry and point comparison
- Separating code into header and source files

## Features

The program provides a console menu with these operations:

- Add a point at the beginning of the list.
- Add a point at the end of the list.
- Add a point in order.
- Delete the first point equal to a selected point.
- Display the points in their original list order.
- Display the points in ascending order.
- Display the points in descending order.
- Free the list before the program exits.

Each point has an `x` and a `y` coordinate. Points are compared by:

1. Polar angle, from `0` to less than `360` degrees.
2. Distance from the origin when the angles are equal.

The sorted views use a temporary array. The
`sorting_by_quicksort` function receives comparison callbacks, so the same
algorithm can sort the array in ascending or descending order.

## Requirements

- GCC or another C11-compatible compiler
- `make`
- A Unix-like environment with the math library

## Build and run

Build the project with:

```sh
make
```

Run the program with:

```sh
./linked_list
```

Remove the executable and generated object files with:

```sh
make clean
```

The project uses these compiler options:

```text
-std=c11 -Wall -Wextra -Wpedantic -g
```

## Project structure

```text
headers/
  tad_list.h       Linked-list types and functions
  tad_point.h      Point type and point functions
  ui.h             Console user-interface functions

sources/
  main.c           Main menu, array management, and quicksort
  tad_list.c       Linked-list operations
  tad_point.c      Point input, comparison, and display
  ui.c             Menu display and input validation

makefile           Build rules
```

## Main learning points

### Linked-list nodes

Each node contains one `point_t` value and a pointer to the next node.
Nodes are allocated with `malloc` and released by `free_list`.

### Double pointers

Functions that can change the first node receive a `node_t **`. For example,
`add_at_beginning` can update the list head through the address of the head
pointer.

### Function pointers

`sorting_by_quicksort` receives Boolean callback functions. The callbacks
define the order used by the partition step. This allows the program to use
the same quicksort implementation for both ascending and descending output.

### Separate responsibilities

The project separates the main program, linked-list operations, point
operations, and user-interface code. This makes each part easier to read and
change.

## Possible improvements

This project is intended for learning. Possible future improvements include:

- Add automated tests for list operations and sorting.
- Handle end-of-file input without retry loops.
- Validate allocation sizes before multiplying by `sizeof(point_t)`.
- Use `size_t` for list sizes and array indexes.
- Use `hypotf` for safer distance calculations.
- Add automatic header dependency tracking to the makefile.


---
#### **Happy coding!** <3
---
