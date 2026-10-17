#pragma once

#ifndef TAD_POINT_H_INCLUDED
#define TAD_POINT_H_INCLUDED

typedef struct
{
    float x;
    float y;
} point_t;

point_t create_point(void);
int compare_points(const point_t first, const point_t second);
void show_point(const point_t point);

#endif
