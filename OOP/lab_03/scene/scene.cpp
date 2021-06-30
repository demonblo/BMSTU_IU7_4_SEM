#include "scene.hpp"

Scene::Scene(): _objects(new Composite) {}

shared_ptr<Composite> Scene::getObjects()
{
    return _objects;
}

void Scene::addObject(std::shared_ptr<Object> obj)
{
    _objects->add(obj);
}

void Scene::removeObject(VectorIterator<std::shared_ptr<Object> > &it)
{
    _objects->remove(it);
}

std::shared_ptr<Object> Scene::getObject(char *model_name)
{
    for (const auto& elem : *_objects)
    {
        if (strcmp(elem->getName(),model_name) == 0)
        {
            return elem;
        }
    }

    time_t t_time = time(NULL);
    throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "Object not found");
}














/*
void Scene::removeModel(VectorIterator<std::shared_ptr<Object> > &it)
{
    _objects->remove(it);
}

void Scene::removeCamera(VectorIterator<std::shared_ptr<Camera> > &it)
{
    _cameras.erase(it);
}

std::shared_ptr<Composite> Scene::getModelsComposite()
{
    return _objects;
}

std::shared_ptr<Camera> Scene::getCamera(std::string cam_name)
{
    int n = _cameras.get_size();
    for (int i = 0; i < n; i++)
    {
        if (_cameras[i]->getName() == cam_name)
        {
            return _cameras[i];
        }
    }

    time_t t_time = time(NULL);
    throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "Object not found");
}

std::shared_ptr<Object> Scene::getObject(std::string model_name)
{
    auto objects = _objects->getObjects();
    int n = objects.get_size();
    for (int i = 0; i < n; i++)
    {
        if (objects[i]->getName() == model_name)
        {
            return objects[i];
        }
    }

    time_t t_time = time(NULL);
    throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "Object not found");
}

void Scene::addModel(std::shared_ptr<Model> obj)
{
    _objects->add(obj);
}

void Scene::addCamera(std::shared_ptr<Camera> obj)
{
    _cameras.push_back(obj);
}

Vector<std::shared_ptr<Object>> Scene::getObjects()
{
    return _objects->getObjects();
}

Vector<std::shared_ptr<Camera>> Scene::getCameras()
{
    return _cameras;
}
*/
