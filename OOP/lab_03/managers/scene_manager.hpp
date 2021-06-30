#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <string>
#include "managers/manager.h"
#include "scene/scene.hpp"
#include "objects/camera/camera.hpp"
#include "exceptions/exceptions.h"
#include <ctime>

class SceneManager: public Manager
{
public:
    SceneManager();

    std::shared_ptr<Scene> getScene();
    void setCurrentCamera(char* name);
    std::shared_ptr<Camera> getCurrentCamera();
private:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> current_camera;
};

#endif // SCENE_MANAGER_HPP
