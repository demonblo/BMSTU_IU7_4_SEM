#ifndef FIGURE_H
#define FIGURE_H
#include "points.h"
#include "links.h"
#include "draw.h"
#include "operations.h"
#include "task_manager.h"

struct figure
{
    points_data points;
    links_data links;
};

figure& init();
int delete_figure(figure& model);
int copy_figure(figure& model, figure& tmp);
int load_figure_from_file(figure& model, load_file load_f);

int draw_figure(figure model, draw arg);

int move_figure(figure& model, move coeff);
int scale_figure(figure& model, scale coeff);
int turn_figure(figure& model, turn coeff);

#endif // FIGURE_H
