#include "facade_viewer.hpp"

FacadeViewer::FacadeViewer()
    : controller(Controller::instance()) {}

void FacadeViewer::executeCommand(std::shared_ptr<Command> command)
{
    command->execute(controller);
}
