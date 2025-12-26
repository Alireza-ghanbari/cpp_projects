#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
class Channel
{
private:
    T buffer;

public:
    void send(const T &data)
    {
        buffer = data;
    }

    T receive() const
    {
        return buffer;
    }
};

class NetworkNode
{
protected:
    string name;

public:
    NetworkNode(const string &name) : name(name) {}

    virtual void info() const = 0;

    virtual ~NetworkNode() = default;
};

template <typename T>
class Endpoint : public NetworkNode
{
private:
    Channel<T> channel;

public:
    Endpoint(const string &name) : NetworkNode(name) {}

    void sendData(const T &data)
    {
        channel.send(data);
    }

    T receiveData() const
    {
        return channel.receive();
    }

    void info() const override
    {
        cout << "Endpoint Name: " << name
             << " | Data Type: " << typeid(T).name()
             << endl;
    }
};

int main()
{
    Endpoint<int> intEndpoint("IntEndpoint");
    Endpoint<string> stringEndpoint("StringEndpoint");

    intEndpoint.sendData(123);
    stringEndpoint.sendData("Hello World");

    cout << intEndpoint.receiveData() << endl;
    cout << stringEndpoint.receiveData() << endl;

    NetworkNode *n1 = &intEndpoint;
    NetworkNode *n2 = &stringEndpoint;

    n1->info();
    n2->info();

    return 0;
}
