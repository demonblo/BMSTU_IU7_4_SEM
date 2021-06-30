#include "cstdio"
#include <cstdlib>
#include "links.h"
#include "figure.h"
#include "error_codes.h"

int read_number_of_links(int* n, FILE* f)
{
    int err = 0;

    if (fscanf(f, "%d", n) != 1)
        err = FILE_FORMAT_ERR;

    if (*n <= 0)
        err = FILE_CONTENT_ERR;

    return err;
}

int links_alloc(links_data &connections, int len)
{
    connections.n = len;

    connections.arr = (link*) calloc(size_t(len), sizeof(link));
    if (!connections.arr)
        return PTR_ALL_ERR;

    return NONE;
}


int links_free(links_data &connections)
{
    if (connections.arr)
        free(connections.arr);
    return NONE;
}


int read_link(link* joints, FILE* f)
{
    if (fscanf(f, "%d-%d", &joints->p1, &joints->p2) != 2)
        return FILE_FORMAT_ERR;

    return NONE;
}


int read_n_links(link* joints, int n, FILE *f)
{
    int err = 0;
    for (int i = 0; i < n && !err; i++)
    {
        if (read_link(&joints[i], f))
            err = FILE_FORMAT_ERR;
    }

    return err;
}


int process_links(links_data& connections, FILE* f)
{
    int n;
    int err = 0;

    err = read_number_of_links(&n, f);
    if (!err)
    {
        if (n)
            err = links_alloc(connections, n);
        else
            err = NO_LINKS;

        if (!err)
        {
            if ((err = read_n_links(connections.arr, n, f)) == FILE_FORMAT_ERR)
                links_free(connections);
        }
    }
    return err;
}
