#ifndef MODEL_BUILDER_HPP
#define MODEL_BUILDER_HPP

#include "memory"
#include "upload/base_model_builder.h"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;

    void reset(char* name) override;
    void addPoint(Point &point) override;
    void addEdge(Edge &edge) override;
    std::shared_ptr<Model> getResult() override;

private:
    std::shared_ptr<Model> model;
};

#endif // MODEL_BUILDER_HPP
