//
// Created by Nilo Neto on 4/30/20.
//

#ifndef HELLOWORLD_OBSERVER_H
#define HELLOWORLD_OBSERVER_H

#include<string>
#include <vector>
#include <iostream>

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
        void addListener(nilolib::Listener* lis) {
            listeners.push_back(lis);
        }

        void doSomething() {
            publish("New Event!");
        }

    };

    class ListenerA : public Listener {
    public:
        explicit ListenerA(Publisher &pub) {
            pub.addListener(this);
        }

        void onEvent(std::string msg) override {
            std::cout << "Listener A received <" << msg << "> from publisher" << std::endl;
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
