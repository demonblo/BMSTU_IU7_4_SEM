#ifndef LINKS_H
#define LINKS_H
#include "points.h"

struct link
{
    int p1;
    int p2;
};

struct links_data
{
    int n;
    link *arr;
};

int links_alloc(links_data &connections, int len);
int links_free(links_data &connections);
int read_link(link* joints, FILE* f);
int read_n_links(link* joints, int n, FILE *f);
int process_links(links_data& connections, FILE* f);

#endif // LINKS_H
