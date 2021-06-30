#include "command.h"

AddCameraAction::AddCameraAction(char *name): _name(name) {}

void AddCameraAction::execute(std::shared_ptr<Controller> controller)
{
    controller->addCamera(_name);
}

AddModelAction::AddModelAction(char *model_name, char* file_name): model_name(model_name), file_name(file_name) {}

void AddModelAction::execute(std::shared_ptr<Controller> controller)
{
    controller->addModel(model_name, file_name);
}

RemoveCameraAction::RemoveCameraAction(char* object_name):
    _object_name(object_name) {}

void RemoveCameraAction::execute(std::shared_ptr<Controller> controller)
{
    controller->removeCamera(_object_name);
}

RemoveModelAction::RemoveModelAction(char* object_name):
    _object_name(object_name) {}

void RemoveModelAction::execute(std::shared_ptr<Controller> controller)
{
    controller->removeModel(_object_name);
}

RenderAction::RenderAction(std::shared_ptr<BaseDrawer> drawer):
    _drawer(drawer){}

void RenderAction::execute(std::shared_ptr<Controller> controller)
{
    controller->draw(_drawer);
}

SetCameraAction::SetCameraAction(char* name): _name(name) {}

void SetCameraAction::execute(std::shared_ptr<Controller> controller)
{
    controller->setCamera(_name);
}

TransformCameraAction::TransformCameraAction(char *object_name, Point& move, Point& rotate):
    _object_name(object_name), _move(move), _rotate(rotate) {}

void TransformCameraAction::execute(std::shared_ptr<Controller> controller)
{
    controller->transformCamera(_object_name, _move, _rotate);
}

TransformModelAction::TransformModelAction(char* object_name, Point& move, Point& scale, Point& rotate):
    _object_name(object_name), _move(move), _scale(scale), _rotate(rotate) {}

void TransformModelAction::execute(std::shared_ptr<Controller> controller)
{
    controller->transformModel(_object_name, _move, _scale, _rotate);
}
