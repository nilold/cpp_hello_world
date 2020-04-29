#ifndef HELLOWORLD_ARRAYLIST_H
#define HELLOWORLD_ARRAYLIST_H

#include <ostream>

namespace nilolib
{
    class ArrayList
    {
    private:
        int m_size = 0;
        int capacity = 0;
        int* m_array{nullptr};

        void grow(){
            capacity *= 2;
            int* new_array = new int[capacity];

            for(unsigned i=0; i<m_size; i++){
                new_array[i] = m_array[i];
            }

            delete[] m_array;
            m_array = new_array;
        };

    public:
        ArrayList(): m_array(new int[10]), capacity(10){};

        explicit ArrayList(int initialCapacity): m_array(new int[initialCapacity]), capacity(initialCapacity){};

        ArrayList(const ArrayList& other){
            std::cout << "Copy constructor called" << std::endl;
            m_size = other.m_size;
            capacity = other.capacity;
            m_array = new int[m_size];
            memcpy(m_array, other.m_array, m_size);
        }

        ArrayList(ArrayList&& other)  noexcept {
            std::cout << "Move constructor called" << std::endl;
            m_size = other.m_size;
            capacity = other.capacity;
            m_array = other.m_array;
            other.m_array = nullptr;
        }

        ~ArrayList(){
            delete[] m_array;
        };

        ArrayList& operator=(const ArrayList& other){
            if(this == &other){
                return *this;
            }

            std::cout << "assigning!" << std::endl;
            m_size = other.m_size;
            capacity = other.capacity;

            delete[] m_array;
            m_array = new int[m_size];

            memcpy(m_array, other.m_array, m_size);

            return *this;
        }

        const int& operator[](int index) const{
            return m_array[index];
        }

        int& operator[](int index){
            return m_array[index];
        }

        void add(const int& value){
            if(m_size == capacity){
                grow();
            }
            m_array[m_size++] = value;
        };

        int remove(int index){
            int removedElement = m_array[index];

            for(unsigned i=index; i<m_size-1; i++){
                m_array[i] = m_array[i+1];
            }
            m_size--;

            return removedElement;
        };

        void set(int index, int value){
            m_array[index] = value;
        };

        const int& get(int index) const{
            return m_array[index];
        };


        int& get(int index){
            return m_array[index];
        };

        int size() const{
            return m_size;
        }
    };

    std::ostream& operator<<(std::ostream &os, const ArrayList &list) {
        for(int i=0; i<list.size(); i++){
            os << list[i] << ",";
        }
        return os << "\b";
    }
}

#endif //HELLOWORLD_ARRAYLIST_H
