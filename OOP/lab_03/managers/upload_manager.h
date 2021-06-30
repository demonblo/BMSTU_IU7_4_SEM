#ifndef UPLOAD_MANAGER_H
#define UPLOAD_MANAGER_H

#include <memory>
#include "managers/manager.h"
#include "upload/base_loader.h"
#include "objects/model/model.hpp"

class UploadManager : public Manager
{
protected:
    std::shared_ptr<BaseLoader> _loader;
public:
    virtual ~UploadManager() = default;
    virtual std::shared_ptr<Model> loadModel(char* model_name, char* source_name) = 0;
};

#endif // UPLOAD_MANAGER_H
