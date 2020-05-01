#ifndef HELLOWORLD_OBSERVER_H
#define HELLOWORLD_OBSERVER_H

#include<string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <stack>

namespace nilolib {
    class Listener {
    public:
        virtual void onEvent(std::string msg) = 0;
    };

    class Publisher {
        std::vector<Listener*> listeners;

        void publish(const std::string &msg) const {
            for (const auto &it : listeners)
                it->onEvent(msg);
        }

    public:
        void addListener(nilolib::Listener *lis) {
            listeners.push_back(lis);
        }

        void doSomething() {
            publish("New Event!");
        }

    };

    class Topic : public Listener {
        std::stack<std::string> messagesStack;



    };

    class ListenerA : public Listener {
        unsigned m_delay;
        unsigned m_id;
    public:
        explicit ListenerA(Publisher &pub, unsigned id, unsigned maxDelay = 1) {
            pub.addListener(this);
            m_id = id;
            m_delay = maxDelay;
        }

        void onEvent(std::string msg) override {
            std::cout << "Listener " << m_id << " received" << msg << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(random() % m_delay));
            std::cout << "Listener " << m_id << " finished" << msg << std::endl;
        }
    };

    class ListenerB : public Listener {
    public:
        explicit ListenerB(Publisher &pub) {
            pub.addListener(this);
        }

        void onEvent(std::string msg) override {
            std::cout << "Listener B received <" << msg << "> from publisher" << std::endl;
        }
    };
}
#endif //HELLOWORLD_OBSERVER_H
