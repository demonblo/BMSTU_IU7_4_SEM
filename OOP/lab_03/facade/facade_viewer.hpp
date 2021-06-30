#ifndef FACADE_VIEWER_HPP
#define FACADE_VIEWER_HPP

#include <memory>
#include "commands/command.h"
#include "controller/controller.hpp"

class FacadeViewer
{
public:
    FacadeViewer();
    FacadeViewer(const FacadeViewer&) = delete;

    ~FacadeViewer() = default;

    void executeCommand(std::shared_ptr<Command> command);

private:
    std::shared_ptr<Controller> controller;
};
#endif  // FACADE_VIEWER_HPP
