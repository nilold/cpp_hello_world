#ifndef HELLOWORLD_ARRAYLIST_H
#define HELLOWORLD_ARRAYLIST_H

#include <ostream>

namespace nilolib {
    class ArrayList {
    public:
    class iterator : public std::iterator<std::random_access_iterator_tag, int>{
        private:
            ArrayList *m_arrayList{nullptr};
            int m_pos{0};

        public:
            iterator(ArrayList &arrayList, int pos) : m_arrayList(&arrayList), m_pos(pos) {}
            iterator(const iterator &it) = default;
            iterator() = delete;

            inline int& operator*() const {return m_arrayList->get(m_pos);}
            inline int* operator->() const {return &operator*();}
//            inline int* operator->() const {return &(*(*this));}

            inline iterator& operator=(const iterator &it){
                if(this == &it){
                    return *this;
                }

                m_arrayList = it.m_arrayList;
                m_pos = it.m_pos;

                return *this;
            }

            inline iterator& operator++() {
                assert(m_pos < m_arrayList->size());
                ++m_pos;
                return *this;
            }

            inline iterator& operator--() {
                assert(m_pos > 0);
                --m_pos;
                return *this;
            }

            inline iterator operator++(int){
                assert(m_pos < m_arrayList->size());
                iterator tmp(*this);
                ++m_pos;
                return tmp;
            }

            inline iterator operator--(int) {
                assert(m_pos > 0);
                iterator tmp(*this);
                --m_pos;
                return tmp;
            }

            inline iterator& operator+=(int rhs) {m_pos += rhs; return *this;}
            inline iterator& operator-=(int rhs) {m_pos -= rhs; return *this;}

            inline int& operator[](int pos) const { return m_arrayList->get(pos);}

            inline iterator& operator+(int offset) {
                assert(m_pos < m_arrayList->size() - offset);
                m_pos += offset;
                return *this;
            }

            inline iterator& operator-(int offset) {
                assert(m_pos > offset);
                m_pos -= offset;
                return *this;
            }

            inline int operator-(const iterator &other) const {return m_pos - other.m_pos;}

            inline bool operator==(const iterator &other) const {return m_pos == other.m_pos;}
            inline bool operator!=(const iterator &other) const {return m_pos != other.m_pos;}
            inline bool operator>(const iterator &other) const {return m_pos > other.m_pos;}
            inline bool operator>=(const iterator &other) const {return m_pos >= other.m_pos;}
            inline bool operator<(const iterator &other) const {return m_pos < other.m_pos;}
            inline bool operator<=(const iterator &other) const {return m_pos <= other.m_pos;}
        };

        ArrayList() : m_array(new int[10]), capacity(10) {};

        explicit ArrayList(int initialCapacity) : m_array(new int[initialCapacity]), capacity(initialCapacity) {};

        ArrayList(const ArrayList &other) {
            std::cout << "Copy constructor called" << std::endl;
            m_size = other.m_size;
            capacity = other.capacity;
            m_array = new int[m_size];
            memcpy(m_array, other.m_array, m_size);
        }

        ArrayList(ArrayList &&other) noexcept {
            std::cout << "Move constructor called" << std::endl;
            m_size = other.m_size;
            capacity = other.capacity;
            m_array = other.m_array;
            other.m_array = nullptr;
        }

        ~ArrayList() {
            delete[] m_array;
        };

        ArrayList &operator=(const ArrayList &other) {
            if (this == &other) {
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

        const int &operator[](int index) const {
            return m_array[index];
        }

        int &operator[](int index) {
            return m_array[index];
        }

        iterator begin() noexcept {
            return iterator(*this, 0);
        }

        iterator end() noexcept {
            return iterator(*this, size()-1);
        }

        void add(const int &value) {
            if (m_size == capacity) {
                grow();
            }
            m_array[m_size++] = value;
        };

        int remove(int index) {
            int removedElement = m_array[index];

            for (unsigned i = index; i < m_size - 1; i++) {
                m_array[i] = m_array[i + 1];
            }
            m_size--;

            return removedElement;
        };

        void set(int index, int value) {
            m_array[index] = value;
        };

        const int &get(int index) const {
            return m_array[index];
        };


        int &get(int index) {
            return m_array[index];
        };

        int size() const {
            return m_size;
        }

    private:
        int m_size = 0;
        int capacity = 0;
        int *m_array{nullptr};

        void grow() {
            capacity *= 2;
            int *new_array = new int[capacity];

            for (unsigned i = 0; i < m_size; i++) {
                new_array[i] = m_array[i];
            }

            delete[] m_array;
            m_array = new_array;
        };
    };

    std::ostream &operator<<(std::ostream &os, ArrayList &list) {
        for(auto value : list){
            os << value << ",";
        }
        return os << "\b";
    }
}

#endif //HELLOWORLD_ARRAYLIST_H
