#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tad_list.h"
#include "ui.h"

static point_t *create_array(int);
static point_t *resize_array(point_t *, int);

bool is_greater(point_t, point_t);
bool is_smaller(point_t, point_t);
static void sorting_by_quicksort(point_t[], int, int,
                                 bool (*)(point_t, point_t),
                                 bool (*)(point_t, point_t));

int main(void)
{

    int option = -1;
    node_t *list_node = NULL;
    point_t point;
    int length = -1;
    point_t *arr_point = NULL;

    bool list_changed = false;

    while (option)
    {

        ui_display_menu();
        option = ui_get_valid_option(0, 5);

        ui_clear_screen();
        switch (option)
        {
        case 1:
        {
            list_changed = true;
            ui_display_header("ADD AT THE START");
            point = create_point();
            add_at_beginning(&list_node, point);
            ui_display_notification("It has been adding successfully");
        }
        break;
        case 2:
        {
            list_changed = true;
            ui_display_header("ADD AT THE END");
            point = create_point();
            add_at_end(&list_node, point);
            ui_display_notification("It has been adding successfully");
        }
        break;

        case 3:
        {
            list_changed = true;
            ui_display_header("ADD THE ORDERLY FASHION");
            point = create_point();
            add_in_order(&list_node, point);
            ui_display_notification("It has been adding successfully");
        }
        break;

        case 4:
        {
            int sub_option = -1;
            int previous_length = -1;
            while (sub_option)
            {
                /** GET POINTS FROM THE NODES */
                length = count_nodes(list_node);

                if (length != previous_length && list_changed)
                {
                    if (arr_point == NULL)
                        arr_point = create_array(length);
                    else
                        arr_point = resize_array(arr_point, length);

                    get_points(list_node, arr_point, length);
                    
                    previous_length = length;
                    list_changed = false;
                }
                /** -------------------------------- */

                ui_display_submenu(length);

                sub_option = ui_get_valid_option(0, 4);

                ui_clear_screen();

                switch (sub_option)
                {

                case 1:
                    ui_display_header("ORIGINAL NODES");
                    // show_list(list_node);
                    for (int i = 0; i < length; i++)
                        show_point(arr_point[i]);
                    ui_pause_screen();

                    break;
                case 2:

                    ui_display_header("ASCENDING NODES");

                    sorting_by_quicksort(arr_point, 0, (length - 1), is_greater, is_smaller);

                    for (int i = 0; i < length; i++)
                        show_point(arr_point[i]);

                    ui_pause_screen();
                    break;
                case 3:

                    ui_display_header("DESCENDING NODES");

                    sorting_by_quicksort(arr_point, 0, (length - 1), is_smaller, is_greater);

                    for (int i = 0; i < length; i++)
                        show_point(arr_point[i]);

                    ui_pause_screen();
                    break;
                }

                ui_clear_screen();
            }
        }
        break;
        case 5:
        {
            list_changed = true;
            ui_display_header("DELETE ONE POINT");
            point = create_point();
            if (delete_node(&list_node, point))
                ui_display_notification("It has been deleting successfully");
            else
                ui_display_notification("The element has not found in the list.");

            ui_pause_screen();
        }
        break;
        }

        ui_clear_screen();
    }

    free_list(&list_node);
    free(arr_point);

    ui_display_notification("SEE YOU SOON");
    return 0;
}

static point_t *create_array(int size)
{
    if (size < 0)
        return NULL;

    point_t *point = (point_t *)calloc(size, sizeof(point_t));

    if (point == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return point;
}

static point_t *resize_array(point_t *pointer, int new_size)
{
    if (new_size < 0)
        return NULL;

    point_t *point = (point_t *)realloc(pointer, new_size * sizeof(point_t));

    if (point == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return point;
}

bool is_greater(point_t a, point_t b) { return compare_points(a, b) > 0; }
bool is_smaller(point_t a, point_t b) { return compare_points(a, b) < 0; }
static void sorting_by_quicksort(point_t arr[], int beginning, int final,
                                 bool (*first_condition)(point_t, point_t),
                                 bool (*second_condition)(point_t, point_t))
{
    point_t pivot;
    int x0, xf;

    if (beginning < final)
    {
        pivot = arr[beginning];
        x0 = beginning;
        xf = final;

        while (x0 < xf)
        {
            while (xf > x0 && (*first_condition)(arr[xf], pivot))
                xf--;

            if (xf > x0)
            {
                arr[x0] = arr[xf];
                x0++;
            }

            while (x0 < xf && (*second_condition)(arr[x0], pivot))
                x0++;

            if (x0 < xf)
            {
                arr[xf] = arr[x0];
                xf--;
            }
        }

        arr[xf] = pivot;
        sorting_by_quicksort(arr, beginning, xf - 1, first_condition, second_condition);
        sorting_by_quicksort(arr, xf + 1, final, first_condition, second_condition);
    }
}
