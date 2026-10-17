#include "tad_list.h"
#include <stdio.h>
#include <stdlib.h>

/** START: PRIVATE METHODS **/
static node_t *allocate_node(void);
static node_t *create_node(point_t);
/** END: PRIVATE METHODS **/

node_t *new_list(void) { return NULL; }

void add_at_beginning(node_t **list, point_t point)
{
    node_t *new_node = create_node(point);

    new_node->next = (*list);
    (*list) = new_node;
}

void add_at_end(node_t **list, point_t point)
{
    // Does list empty ?
    if ((*list) == NULL)
    {
        (*list) = create_node(point);
        return;
    }

    node_t *current = *list; // Access the memory address of single pointer

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = create_node(point);
}

void show_list(const node_t *list)
{
    if (list == NULL)
    {
        printf("Warming: there's not element in the linked list.\n");
        return;
    }

    while (list != NULL)
    {
        show_point(list->point);
        list = list->next;
    }
}

void add_in_order(node_t **list, point_t point)
{
    node_t *new_node = create_node(point);

    if ((*list) == NULL)
    {
        (*list) = new_node;
        return;
    }

    node_t *current = (*list);
    node_t *before = NULL;

    while (current != NULL &&
           compare_points(current->point, point) < 0)
    {
        before = current;
        current = current->next;
    }

    if (before == NULL)
    {
        // add_at_beginning(list, point);
        new_node->next = (*list);
        (*list) = new_node;
        return;
    }

    before->next = new_node;
    new_node->next = current;
}

void free_list(node_t **list)
{
    while ((*list) != NULL)
    {
        node_t *node = (*list);
        (*list) = node->next;
        free(node);
    }
}

int delete_node(node_t **list, point_t point)
{
    // Early return
    if ((*list) == NULL)
        return 0;

    node_t *current = (*list);
    node_t *before = NULL;

    while (current != NULL && compare_points(current->point, point) != 0)
    {
        before = current;
        current = current->next;
    }

    if (current == NULL) // Element not found
        return 0;

    if (before == NULL) // Delete: in the beginning
        (*list) = current->next;
    else
        before->next = current->next;

    free(current);
    return 1;
}

int count_nodes(const node_t *list)
{
    if (list == NULL)
        return 0;

    int count = 0;

    while (list != NULL)
    {
        count++;
        list = list->next;
    }

    return count;
}

void get_points(const node_t *list, point_t *arr, int size)
{
    if (list == NULL)
        return;

    // node_t *current = (*list);
    int i = 0;

    while (list != NULL && i < size)
    {
        *(arr + i) = list->point;
        i++;
        list = list->next;
    }
}

/*------------------------------------------------------------------------------------------------*/
/** PRIVATES FUNCTIONS **/
/*------------------------------------------------------------------------------------------------*/

static node_t *allocate_node(void)
{
    // node_t *node = malloc(sizeof(*node));
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (node == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return node;
}

static node_t *create_node(point_t point)
{
    node_t *node = allocate_node();

    node->point = point;
    node->next = NULL;
    return node;
}

