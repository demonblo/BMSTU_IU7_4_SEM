#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>
#include <memory>

#include "managers/camera_manager.hpp"
#include "managers/scene_manager.hpp"
#include "managers/upload_manager.h"
#include "upload/file_loader.hpp"
#include "upload/model_builder.hpp"
#include "upload/upload_model.hpp"
#include "upload/director_model.hpp"
#include "managers/transform_manager.hpp"
#include "managers/render_manager.hpp"

class Controller
{
public:
    static std::shared_ptr<Controller> instance();
    Controller(const Controller&) = delete;

    Controller& operator=(const Controller&) = delete;
    ~Controller() = default;

    void addModel(char* model_name, char *file_name);
    void addCamera(char* cam_name);
    void setCamera(char* cam_name);
    void removeCamera(char* cam_name);
    void removeModel(char* model_name);

    void transformCamera(char* cam_name, Point &move, Point &rotate);
    void transformModel(char* model_name, Point &move, Point &scale, Point &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer);

private:
    Controller();
    CameraManager camera_manager;
    SceneManager scene_manager;
    TransformManager transform_manager;
    std::shared_ptr<UploadManager> upload_manager;
    std::shared_ptr<RenderManager> renderer;
};


#endif  // CONTROLLER_HPP
