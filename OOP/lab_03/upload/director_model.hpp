#ifndef DIRECTOR_MODEL_HPP
#define DIRECTOR_MODEL_HPP

#include <memory>
#include "objects/model/model.hpp"
#include "upload/base_model_builder.h"

class DirectorModel
{
private:
    std::shared_ptr<BaseModelBuilder> builder;
public:
    std::shared_ptr<Model> build_model(Vector<Point> &points, Vector<Edge> &edges);
    void setBuilder(std::shared_ptr<BaseModelBuilder> builder);
};

#endif // DIRECTOR_MODEL_HPP
