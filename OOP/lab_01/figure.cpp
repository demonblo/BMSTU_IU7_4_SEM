#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error_codes.h"
#include "points.h"
#include "links.h"
#include "draw.h"
#include "scene.h"
#include "operations.h"
#include "task_manager.h"

figure& init()
{
    static figure model;

    model.points.n = 0;
    model.points.arr = nullptr;

    model.links.n = 0;
    model.links.arr = nullptr;

    return model;
}


int delete_figure(figure& model)
{
    model.points.n = 0;
    points_free(model.points);

    model.links.n = 0;
    links_free(model.links);
    return NONE;
}

int copy_figure(figure& model, figure& tmp)
{
    model.points.n = tmp.points.n;
    model.points.arr = tmp.points.arr;

    model.links.n = tmp.links.n;
    model.links.arr = tmp.links.arr;
    return NONE;
}

const char* get_file_name(load_file load_f)
{
    return load_f.filename;
}

int load_figure_from_file(figure& model, load_file load_f)
{
    FILE *f = fopen(get_file_name(load_f), "r");
    if (!f)
        return FILE_NOT_FOUND;
    figure model_tmp = init();

    int err = process_points(model_tmp.points, f);
    if (!err)
    {
        err = process_links(model_tmp.links, f);
        if (err)
            points_free(model_tmp.points);
    }

    fclose(f);

    if (!err)
    {
        err = delete_figure(model);
        if (!err)
        {
            err = copy_figure(model, model_tmp);
        }
    }
    if (err)
         points_free(model_tmp.points);

    return err;
}

int set_rect_and_scene(graphics a, draw arg)
{
    a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.w, arg.h)));
    set_scene(arg.gV, a);
    return NONE;
}


int draw_figure(figure model, draw arg)
{
    graphics a;

    int err = init_scene(a, arg.gV);
    if (err)
        return err;

    draw_links(model.points, model.links, arg, a);
    set_rect_and_scene(a, arg);

    return err;
}

int move_figure(figure& model, move coeff)
{
    return move_points_array(model.points.arr, model.points.n, coeff);
}

int scale_figure(figure& model, scale coeff)
{
    return scale_points_array(model.points.arr, model.points.n, coeff);
}

int turn_figure(figure& model, turn coeff)
{
    return rotate_points_array(model.points.arr, model.points.n, coeff);
}

