/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** show intersection points
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_macro_abs.h"

int intersection_cone(int *p, int *v, int param)
{
    float tanparam = powf(tanf((param * M_PI) / 180), 2);
    float a = (powf(v[0], 2) + powf(v[1], 2)) - (powf(v[2], 2) * tanparam);
    float b = ((2 * (p[0] * v[0])) +
               (2 * (p[1] * v[1]))) - ((2 * p[2] * v[2]) * tanparam);
    float c = (powf(p[0], 2) + powf(p[1], 2)) - (powf(p[2], 2) * tanparam);
    float delta = powf(b, 2) - (4 * (a * c));
    float x1;
    float x2;

    printf("Cone with a %d degree angle\n", param);
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", p[0], p[1], p[2], v[0], v[1], v[2]);
    if (delta == 0) {
        if (a == 0)
            printf("There is an infinite number of intersection points.\n");
        else {
            x1 = (-b) / (2 * a);
            printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n"
                 , p[0] + (v[0] * x1), p[1] + (v[1] * x1), p[2] + (v[2] * x1));
        }
    }
    else if (delta > 0) {
        x1 = ((-b) + sqrtf(delta)) / (2 * a);
        x2 = ((-b) - sqrtf(delta)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n"
               , p[0] + (v[0] * x1), p[1] + (v[1] * x1), p[2] + (v[2] * x1));
        printf("(%.3f, %.3f, %.3f)\n"
               , p[0] + (v[0] * x2), p[1] + (v[1] * x2), p[2] + (v[2] * x2));
    }
    else
        printf("No intersection point.\n");
    return (0);
}

int intersection_cylindre(int *p, int *v, int param)
{
    float a = powf(v[0], 2) + powf(v[1], 2);
    float b = (2 * (p[0] * v[0])) + (2 * (p[1] * v[1]));
    float c = (powf(p[0], 2) + powf(p[1], 2)) - powf(param, 2);
    float delta = powf(b, 2) - (4 * (a * c));
    float x1;
    float x2;

    printf("Cylinder of radius %d\n", param);
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", p[0], p[1], p[2], v[0], v[1], v[2]);
    if (delta == 0) {
        if ((v[0] == 0) && (v[1] == 0) && (c == 0))
            printf("There is an infinite number of intersection points.\n");
        else {
            x1 = (-b) / (2 * a);
            printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n"
                 , p[0] + (v[0] * x1), p[1] + (v[1] * x1), p[2] + (v[2] * x1));
        }
    }
    else if (delta > 0) {
        x1 = ((-b) + sqrtf(delta)) / (2 * a);
        x2 = ((-b) - sqrtf(delta)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n"
               , p[0] + (v[0] * x1), p[1] + (v[1] * x1), p[2] + (v[2] * x1));
        printf("(%.3f, %.3f, %.3f)\n"
               , p[0] + (v[0] * x2), p[1] + (v[1] * x2), p[2] + (v[2] * x2));
    }
    else
        printf("No intersection point.\n");
    return (0);
}

int intersection_sphere(int *p, int *v, int param)
{
    float a = powf(v[0], 2) + powf(v[1], 2) + powf(v[2], 2);
    float b = (2 * (p[0] * v[0])) + (2 * (p[1] * v[1])) + (2 * (p[2] * v[2]));
    float c = (powf(p[0], 2) + powf(p[1], 2) + powf(p[2], 2)) - powf(param, 2);
    float delta = powf(b, 2) - (4 * (a * c));
    float x1;
    float x2;

    printf("Sphere of radius %d\n", param);
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", p[0], p[1], p[2], v[0], v[1], v[2]);
    if (delta == 0) {
        x1 = (-b) / (2 * a);
        printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n"
            , p[0] + (v[0] * x1), p[1] + (v[1] * x1), p[2] + (v[2] * x1));
        }
    else if (delta > 0) {
        x1 = ((-b) + sqrtf(delta)) / (2 * a);
        x2 = ((-b) - sqrtf(delta)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n"
               , p[0] + (v[0] * x1), p[1] + (v[1] * x1), p[2] + (v[2] * x1));
        printf("(%.3f, %.3f, %.3f)\n"
               , p[0] + (v[0] * x2), p[1] + (v[1] * x2), p[2] + (v[2] * x2));
    }
    else
        printf("No intersection point.\n");
    return (0);
}

int main(int ac, char const **av)
{
    int *point = malloc(sizeof(int) * 4);
    int *vector = malloc(sizeof(int) * 4);
    int param;

    if (ac == 9) {
        point[0] = my_getnbr(av[2]);
        point[1] = my_getnbr(av[3]);
        point[2] = my_getnbr(av[4]);
        vector[0] = my_getnbr(av[5]);
        vector[1] = my_getnbr(av[6]);
        vector[2] = my_getnbr(av[7]);
        param = ABS(my_getnbr(av[8]));
        if (av[1][0] == '1')
            intersection_sphere(point, vector, param);
        else if (av[1][0] == '2')
            intersection_cylindre(point, vector, param);
        else if (av[1][0] == '3')
            intersection_cone(point, vector, param);
    }
    else
        return (84);
    return (0);
}
