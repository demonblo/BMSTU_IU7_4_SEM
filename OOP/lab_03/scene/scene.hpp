#ifndef SCENE_HPP
#define SCENE_HPP

#include <unordered_map>
#include <memory>
#include "exceptions/exceptions.h"
#include "objects/object_composite.hpp"
#include "objects/object.hpp"
#include "vector/vector.h"
#include "vector/vector_iterator.hpp"
#include <cstring>

class Scene
{
public:
    Scene();

    void addObject(std::shared_ptr<Object> obj);
    void removeObject(VectorIterator<std::shared_ptr<Object>>& it);

    std::shared_ptr<Object> getObject(char* object);
    std::shared_ptr<Composite> getObjects();
private:
    std::shared_ptr<Composite> _objects;
};



















/*class Scene
{
public:
    Scene();

    void addModel(std::shared_ptr<Model> obj);
    void addCamera(std::shared_ptr<Camera> obj);
    void removeModel(VectorIterator<std::shared_ptr<Object>> &it);
    void removeCamera(VectorIterator<std::shared_ptr<Camera>>& it);

    std::shared_ptr<Composite> getModelsComposite();
    std::shared_ptr<Camera> getCamera(std::string cam_name);
    std::shared_ptr<Object> getObject(std::string model_name);
    Vector<std::shared_ptr<Object> > getObjects();
    Vector<std::shared_ptr<Camera> > getCameras();
private:
    std::shared_ptr<Composite> _objects;
    Vector<std::shared_ptr<Camera>> _cameras;
};*/

#endif // SCENE_HPP
