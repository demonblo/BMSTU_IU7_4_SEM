#include "cstdio"
#include <cstdlib>
#include "points.h"
#include "figure.h"
#include "error_codes.h"


int read_number_of_points(int* n, FILE* f)
{
    int err = 0;

    if (fscanf(f, "%d", n) != 1)
        err = FILE_FORMAT_ERR;

    if (*n <= 0)
        err = FILE_CONTENT_ERR;

    return err;
}

int points_alloc(points_data& pts, int len)
{
    pts.n = len;
    pts.arr = (point*) calloc(size_t(len), sizeof(point));

    if (!pts.arr)
        return PTR_ALL_ERR;

    return NONE;
}


int points_free(points_data &pts)
{
    if (pts.arr)
        free(pts.arr);
    return NONE;
}


int read_point(point* dot, FILE* f)
{
    if (fscanf(f, "%lf%lf%lf", &dot->x, &dot->y, &dot->z) != 3)
        return FILE_FORMAT_ERR;

    return NONE;
}


int read_n_points(point *dots, int n, FILE *f)
{
    int err = 0;
    for (int i = 0; i < n && !err; i++)
    {
        if (read_point(&dots[i], f))
            err = FILE_FORMAT_ERR;
    }
    return err;
}


int process_points(points_data &pts, FILE *f)
{
    int n;
    int err = 0;

    err = read_number_of_points(&n, f);
    if (!err)
    {
        if (n)
            err = points_alloc(pts, n);
        else
            err = NO_DOTS;

        if (!err)
        {
            if ((err = read_n_points(pts.arr, n, f)) == FILE_FORMAT_ERR)
                points_free(pts);
        }
    }
    return err;
}
