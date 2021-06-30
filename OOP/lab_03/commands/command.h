#ifndef COMMAND_H
#define COMMAND_H

#include "controller/controller.hpp"
#include "point/point.hpp"
#include <memory>
#include <string>

class Controller;

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(std::shared_ptr<Controller>) = 0;
};


class AddCameraAction: public Command
{
public:
    explicit AddCameraAction(char*);
    void execute(std::shared_ptr<Controller>) override;
private:
    char* _name;
};

class AddModelAction: public Command
{
public:
    explicit AddModelAction(char*, char*);

    void execute(std::shared_ptr<Controller>) override;
private:
    char* model_name;
    char* file_name;
};

class RemoveCameraAction: public Command
{
public:
    RemoveCameraAction(char *);
    void execute(std::shared_ptr<Controller>) override;
private:
    char* _object_name;
};

class RemoveModelAction: public Command
{
public:
    RemoveModelAction(char *);
    void execute(std::shared_ptr<Controller>) override;
private:
    char* _object_name;
};

class RenderAction: public Command
{
public:
    explicit RenderAction(std::shared_ptr<BaseDrawer>);
    void execute(std::shared_ptr<Controller>) override;
private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<AbstractGraphFactory> _factory;
};

class SetCameraAction: public Command
{
public:
    explicit SetCameraAction(char*);
    void execute(std::shared_ptr<Controller>) override;
private:
    char* _name;
};

class TransformCameraAction: public Command
{
public:
    TransformCameraAction(char*, Point&, Point&);
    void execute(std::shared_ptr<Controller>) override;
private:
    char* _object_name;
    Point _move;
    Point _rotate;
};

class TransformModelAction: public Command
{
public:
    TransformModelAction(char*, Point&, Point&, Point&);
    void execute(std::shared_ptr<Controller>) override;
private:
    char* _object_name;
    Point _move;
    Point _scale;
    Point _rotate;
};




#endif // COMMAND_H
