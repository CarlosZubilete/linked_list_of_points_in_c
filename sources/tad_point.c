#include "tad_point.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/** PRIVATE METHODS **/
static float get_valid_real(void);
static float get_magnitude(const point_t);
static float get_angle(const point_t);
/** END: PRIVATE METHODS **/

point_t create_point(void)
{
    point_t point;

    printf("Enter the coordinate in x: \n");
    point.x = get_valid_real();
    printf("Enter the coordinate in y: \n");
    point.y = get_valid_real();

    return point;
}

/** COMPARE THE ANGLES BETWEEN THEM  **/
int compare_points(const point_t first, const point_t second)
{
    float angle_first = get_angle(first);
    float angle_second = get_angle(second);

    if (angle_first < angle_second)
        return -1;

    if (angle_first > angle_second)
        return 1;

    // The angles are equal: compare magnitudes.
    float magnitude_first = get_magnitude(first);
    float magnitude_second = get_magnitude(second);

    if (magnitude_first < magnitude_second)
        return -1;

    if (magnitude_first > magnitude_second)
        return 1;

    return 0;
}

void show_point(const point_t point)
{
    printf("Point (x:%g , y:%g)\tAngle = %.2f°\t|M| = %.2f\n", point.x, point.y, get_angle(point), get_magnitude(point));
}

/*------------------------------------------------------------------------------------------------*/
/** PRIVATES FUNCTIONS **/
/*------------------------------------------------------------------------------------------------*/

static float get_valid_real(void)
{
    float input;
    while (scanf("%f", &input) != 1)
    {
        // Clear the invalid input from the buffer
        while (getchar() != '\n')
            ;
        printf("(Just reals number): ");
    }

    // Clear the leftover '\n' after a successful input
    while (getchar() != '\n')
        ;

    return input;
}

static float get_magnitude(const point_t point)
{
    return sqrtf((point.x * point.x) + (point.y * point.y));
}

/**  TAN = sen/cos || TAN = y/x **/
static float get_angle(const point_t point)
{
    // Get the angle from -180 to 180 degrees
    float angle = atan2f(point.y, point.x) * (180 / M_PI);

    if (angle < 0)
        angle += 360.f;

    return angle;
}