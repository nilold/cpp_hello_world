#include <iostream>
#include "ArrayList.h"

void foo(nilolib::ArrayList arr){
    arr[0] = 5;
}

int main() {
    nilolib::ArrayList a(1);
    nilolib::ArrayList b = nilolib::ArrayList();

    b.add(10);

    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);

    foo(a);

    std::cout << "a = " << a << " (size=" << a.size() << ")" << std::endl;

    return 0;
}

