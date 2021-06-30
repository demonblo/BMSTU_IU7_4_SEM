#include "upload/upload_model.hpp"

UploadModel::UploadModel(std::shared_ptr<BaseLoader> ldr, std::shared_ptr<BaseModelBuilder> bld)
{
    _loader = ldr;
    _builder = bld;
}

std::shared_ptr<Model> UploadModel::loadModel(char* model_name, char* source_name)
{
    _loader->open(source_name);
    _builder->reset(model_name);

    Vector<Point> points;
    Vector<Edge> edges;

    int count = _loader->readCountInfo();

    for (int i = 0; i < count; i++)
    {
        points.push_back(_loader->readPoint());
    }

    count = _loader->readCountInfo();

    for (int i = 0; i < count; i++)
    {
        edges.push_back(_loader->readEdgeInfo());
    }

    _loader->close();
    DirectorModel director;
    director.setBuilder(_builder);
    return director.build_model(points, edges);

}

