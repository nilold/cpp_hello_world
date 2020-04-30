#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include "ArrayList.h"
#include "design-patterns/adapter.h"

void useArrayList();
void useVector();
void useUnorderedSet();
void useSet();
nilolib::ArrayList<int> makeIntArray(int);

void useAdapter();

namespace std {
    using namespace nilolib;

    template<>
    class hash<ArrayList<int>> {
    public:
        size_t operator()(const ArrayList<int> &a) const {
            cout << "hash" << endl;
            return hash<int>()(a.size());
        }
    };
}

int main() {
//    useArrayList();
//    useVector();
//    useUnorderedSet();
//    useSet();
    useAdapter();
}

void useAdapter(){
    nilolib::String str("Hi Nilo Serafim Neto");

//    auto words_vector_ptr = str.split();

    for(auto &it : str.split())
        std::cout << it << std::endl;
}

//void useUnorderedSet(){
//    std::unordered_set<nilolib::ArrayList<int>> s;
//
//    s.insert(makeIntArray(15));
//    s.insert(makeIntArray(15));
//    s.insert(makeIntArray(15));
////    s.insert(makeIntArray(15));
////    s.insert(makeIntArray(15));
//
//}

void useSet(){
    std::set<nilolib::ArrayList<int>> s;

    s.insert(makeIntArray(15));
    s.insert(makeIntArray(12));
    s.insert(makeIntArray(15));
    s.insert(makeIntArray(15));
    s.insert(makeIntArray(15));
    s.insert(makeIntArray(15));
    s.insert(makeIntArray(12));
    s.insert(makeIntArray(12));
    s.insert(makeIntArray(12));
    s.insert(makeIntArray(10));
}

nilolib::ArrayList<int> makeIntArray(int size){
    nilolib::ArrayList<int> a(size);
    for(unsigned i=0; i<size; i++){
        a.add(random());
    }
    return a;
}

void useVector(){
    std::vector<int> myVector;

    myVector.push_back(3);
    myVector.push_back(8);
    myVector.push_back(3000);
    myVector.push_back(33);
    myVector.push_back(4);
    myVector.push_back(-50);

    std::sort(myVector.begin(), myVector.end());

    for(auto it : myVector){
        std::cout << it << std::endl;
    }

}

void useArrayList() {
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
}

