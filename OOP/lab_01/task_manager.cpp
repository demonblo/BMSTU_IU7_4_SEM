#include "task_manager.h"
#include "error_codes.h"
#include "operations.h"
#include "figure.h"

int task_manager(request wrequest)
{
    static figure model = init();
    int  err = 0;

    switch (wrequest.type)
    {
    case INIT:
        break;
    case LOAD_FILE:
        err = load_figure_from_file(model, wrequest.load_f); //wrequest.load_f.filename
        break;
    case DRAW:
        err = draw_figure(model, wrequest.dr);
        break;
    case MOVE:
        err = move_figure(model, wrequest.mo);
        break;
    case SCALE:
        err = scale_figure(model, wrequest.sc);
        break;
    case TURN:
        err = turn_figure(model, wrequest.tu);
        break;
    case QUIT:
        delete_figure(model);
        break;
    default:
        err = UNKNOWN_COMMAND;
    }

    return err;
}
