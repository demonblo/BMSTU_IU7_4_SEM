#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include "controller/controller.hpp"
#include "command/command.hpp"

class Facade
{
public:
    Facade();
    Facade(const Facade&) = delete;

    ~Facade() = default;

    void ExecuteCommand(Command& command);

private:
    std::shared_ptr<Controller> controller;
};

#endif  // FACADE_H
