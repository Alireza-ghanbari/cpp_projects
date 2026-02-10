#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

class ResourceManager;

class ResourceListener
{
public:
    virtual ~ResourceListener() = default;
    virtual void onResourceUpdated() = 0;
};

class Resource : public enable_shared_from_this<Resource>
{
private:
    string id;
    weak_ptr<ResourceManager> manager;
    vector<weak_ptr<ResourceListener>> listeners;

public:
    Resource(const string &id, shared_ptr<ResourceManager> mgr)
        : id(id), manager(mgr)
    {
        cout << "Resource Created: " << id << endl;
    }

    ~Resource()
    {
        cout << "Resource Destroyed: " << id << endl;
    }

    void addListener(shared_ptr<ResourceListener> listener)
    {
        listeners.push_back(listener);
    }

    void notifyUpdate()
    {
        for (auto it = listeners.begin(); it != listeners.end();)
        {
            if (auto spt = it->lock())
            {
                spt->onResourceUpdated();
                ++it;
            }
            else
            {
                it = listeners.erase(it);
            }
        }
    }

    string getId() const { return id; }
};

class ResourceManager : public enable_shared_from_this<ResourceManager>
{
private:
    unordered_map<string, weak_ptr<Resource>> cache;

public:
    shared_ptr<Resource> get(const string &id)
    {
        if (cache.count(id))
        {
            if (auto existing = cache[id].lock())
            {
                cout << "Returning cached resource: " << id << endl;
                return existing;
            }
        }

        auto newResource = make_shared<Resource>(id, shared_from_this());
        cache[id] = newResource;
        return newResource;
    }

    void cleanCache()
    {
        for (auto it = cache.begin(); it != cache.end();)
        {
            if (it->second.expired())
            {
                it = cache.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
};

class Logger : public ResourceListener
{
public:
    void onResourceUpdated() override
    {
        cout << "Logger: Resource has been updated." << endl;
    }
};

int main()
{
    auto manager = make_shared<ResourceManager>();

    {
        auto res1 = manager->get("texture.png");
        auto res2 = manager->get("texture.png");

        cout << "Use Count: " << res1.use_count() << endl;

        auto logger = make_shared<Logger>();
        res1->addListener(logger);
        res1->notifyUpdate();
    }

    cout << "After scope block..." << endl;

    auto res3 = manager->get("texture.png");

    return 0;
}