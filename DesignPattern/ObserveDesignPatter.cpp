#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

// Consumer Interface
class Consumer 
{
    public:
    virtual void notification(const string& message) = 0;
    virtual ~Consumer() {}
};

// Producer Interface
class Producer 
{
    public:
    virtual void attach(shared_ptr<Consumer> consumer) = 0;
    virtual void detach(shared_ptr<Consumer> consumer) = 0;
    virtual void notifyConsumers() = 0;
    virtual ~Producer() {}
};

// Concrete Producer
class MessageProducer : public Producer 
{
    private:
    vector<shared_ptr<Consumer>> consumers;
    string message;

    public:
    void setMessage(const string& newMessage) 
    {
        message = newMessage;
        notifyConsumers();
    }

    void attach(shared_ptr<Consumer> consumer) override 
    {
        consumers.push_back(consumer);
    }

    void detach(shared_ptr<Consumer> consumer) override 
    {
        consumers.erase(remove(consumers.begin(), consumers.end(), consumer), consumers.end());
    }

    void notifyConsumers() override 
    {
        for (auto& consumer : consumers) 
        {
            if (consumer) 
            {
                consumer->notification(message);
            }
        }
    }
};

// Concrete Consumer
class MessageConsumer : public Consumer 
{
    private:
    string name;

    public:
    MessageConsumer(const string& consumerName) : name(consumerName) {}

    void notification(const string& message) override 
    {
        cout << name << " received notification: " << message << endl;
    }
};

// Main
int main() 
{
    MessageProducer producer;

    auto consumer1 = make_shared<MessageConsumer>("Consumer A");
    auto consumer2 = make_shared<MessageConsumer>("Consumer B");

    producer.attach(consumer1);
    producer.attach(consumer2);

    producer.setMessage("📢 Message from Producer using 'notification()' method!");

    return 0;
}


op
Consumer A received notification: 📢 Message from Producer using 
'notification()' method!
Consumer B received notification: 📢 Message from Producer using 
'notification()' method!
    





#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Consumer Interface (was Observer)
class Consumer
{
    public:
    virtual void notification(const string& message) = 0;
    virtual ~Consumer() {}
};

// Producer Interface (was Subject)
class Producer 
{
    public:
    virtual void attach(Consumer* consumer) = 0;
    virtual void detach(Consumer* consumer) = 0;
    virtual void notifyConsumers() = 0;
    virtual ~Producer() {}
};

// Concrete Producer
class MessageProducer : public Producer 
{
    private:
    vector<Consumer*> consumers;
    string message;

    public:
    void setMessage(const string& newMessage) 
    {
        message = newMessage;
        notifyConsumers();
    }

    void attach(Consumer* consumer) override 
    {
        consumers.push_back(consumer);
    }

    void detach(Consumer* consumer) override 
    {
        consumers.erase(remove(consumers.begin(), 
       consumers.end(), consumer), consumers.end());
    }

    void notifyConsumers() override 
    {
        for (Consumer* consumer : consumers) {
            consumer->notification(message);
        }
    }
};

// Concrete Consumer
class MessageConsumer : public Consumer 
{
    private:
    string name;

    public:
    MessageConsumer(const string& consumerName) : name(consumerName) {}

    void notification(const string& message) override 
    {
        cout << name << " received message: " << message << endl;
    }
};

// Main
int main() 
{
    MessageProducer producer;

    MessageConsumer consumer1("Consumer A");
    MessageConsumer consumer2("Consumer B");

    producer.attach(&consumer1);
    producer.attach(&consumer2);

    producer.setMessage("🚨 Message from Producer!");

    return 0;
}
