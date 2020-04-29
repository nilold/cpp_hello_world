#include <iostream>
#include <algorithm>
#include <string>
#include "ArrayList.h"

int main() {
    nilolib::ArrayList<int> a(1);
    nilolib::ArrayList<float> b = nilolib::ArrayList<float>();
    nilolib::ArrayList<std::string> c(10);

    c.add("Nilo");
    c.add("João");
    c.add("...");
    c.add("D");
    c.add("d");
    c.add("A");

    b.add(10.0);
    b.add(3.14);
    b.add(25.0);
    b.add(12.13);
    b.add(237832.2442);

    a.add(5);
    a.add(1);
    a.add(3);
    a.add(2);
    a.add(4);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    std::cout << "a = " << a << " (size=" << a.size() << ")" << std::endl;
    std::cout << "b = " << b << " (size=" << b.size() << ")" << std::endl;
    std::cout << "c = " << c << " (size=" << c.size() << ")" << std::endl;

    return 0;
}

