#pragma once

#ifndef TAD_LIST_H_INCLUDED
#define TAD_LIST_H_INCLUDED
#include "tad_point.h"

/** NODE **/
typedef struct node
{
    point_t point;
    struct node *next;
} node_t;

node_t *new_list(void);
void add_at_beginning(node_t **, point_t);
void add_at_end(node_t **, point_t);
void show_list(const node_t *);
void add_in_order(node_t **, point_t);
int delete_node(node_t **, point_t);
void free_list(node_t **);
int count_nodes(const node_t *);

void get_points(const node_t *, point_t *, int);

#endif
