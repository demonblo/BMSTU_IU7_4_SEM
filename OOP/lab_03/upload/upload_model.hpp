#ifndef UPLOAD_MODEL_HPP
#define UPLOAD_MODEL_HPP

#include <memory>
#include "managers/upload_manager.h"
#include "upload/base_model_builder.h"
#include "upload/director_model.hpp"

class UploadModel: public UploadManager
{
public:
    UploadModel(std::shared_ptr<BaseLoader> ldr, std::shared_ptr<BaseModelBuilder> bld);
    std::shared_ptr<Model> loadModel(char* model_name, char *source_name) override;
private:
    std::shared_ptr<BaseModelBuilder> _builder;
};

#endif // UPLOAD_MODEL_HPP
