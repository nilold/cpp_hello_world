#ifndef HELLOWORLD_ARRAYLIST_H
#define HELLOWORLD_ARRAYLIST_H

#include <ostream>

namespace nilolib {
    template<typename T>
    class ArrayList {
    public:
        class iterator;

        ArrayList() : m_array(new T[10]), capacity(10) {};

        explicit ArrayList(int initialCapacity) : m_array(new T[initialCapacity]), capacity(initialCapacity) {};

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
            return iterator(*this, size());
        }

        void add(const T &value) {
            if (m_size == capacity) {
                grow();
            }
            m_array[m_size++] = value;
        };

        T remove(int index) {
            T removedElement = m_array[index];

            for (unsigned i = index; i < m_size - 1; i++) {
                m_array[i] = m_array[i + 1];
            }
            m_size--;

            return removedElement;
        };

        void set(int index, T value) {
            m_array[index] = value;
        };

        const T &get(int index) const {
            return m_array[index];
        };


        T &get(int index) {
            return m_array[index];
        };

        int size() const {
            return m_size;
        }

    private:
        int m_size = 0;
        int capacity = 0;
        T *m_array{nullptr};

        void grow() {
            capacity *= 2;
            T *new_array = new T[capacity];

            for (unsigned i = 0; i < m_size; i++) {
                new_array[i] = m_array[i];
            }

            delete[] m_array;
            m_array = new_array;
        };
    };

    template<typename T>
    class ArrayList<T>::iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        ArrayList *m_arrayList{nullptr};
        int m_pos{0};

    public:
        iterator(ArrayList &arrayList, int pos) : m_arrayList(&arrayList), m_pos(pos) {}

        iterator(const iterator &it) = default;

        iterator() = delete;

        inline T &operator*() const { return m_arrayList->get(m_pos); }

        inline T *operator->() const { return &operator*(); }

        inline iterator &operator=(const iterator &it) {
            if (this == &it) {
                return *this;
            }

            m_arrayList = it.m_arrayList;
            m_pos = it.m_pos;

            return *this;
        }

        inline iterator &operator++() {
            ++m_pos;
            return *this;
        }

        inline iterator &operator--() {
            --m_pos;
            return *this;
        }

        inline iterator operator++(int) {
            iterator tmp(*this);
            ++m_pos;
            return tmp;
        }

        inline iterator operator--(int) {
            iterator tmp(*this);
            --m_pos;
            return tmp;
        }

        inline iterator &operator+=(int rhs) {
            std::cout << "shift " << rhs << " positions right" << std::endl;
            m_pos += rhs;
            return *this;
        }

        inline iterator &operator-=(int rhs) {
            std::cout << "shift " << rhs << " positions left" << std::endl;
            m_pos -= rhs;
            return *this;
        }

        inline iterator operator+(int offset) const{
            iterator tmp(*this);
            tmp.m_pos += offset;
            return tmp;
        }

        inline iterator operator-(int offset) {
            iterator tmp(*this);
            tmp.m_pos -= offset;
            return tmp;
        }

        inline int operator-(const iterator other) const{
            return m_pos - other.m_pos;
        }

        inline iterator operator+(const iterator &other) const {
            iterator tmp(*this);
            tmp.m_pos += other.m_pos;
            return tmp;
        }


        inline T &operator[](int pos) const { return m_arrayList->get(pos); }

        inline bool operator==(const iterator &other) const { return m_pos == other.m_pos; }

        inline bool operator!=(const iterator &other) const { return m_pos != other.m_pos; }

        inline bool operator>(const iterator &other) const { return m_pos > other.m_pos; }

        inline bool operator>=(const iterator &other) const { return m_pos >= other.m_pos; }

        inline bool operator<(const iterator &other) const { return m_pos < other.m_pos; }

        inline bool operator<=(const iterator &other) const { return m_pos <= other.m_pos; }
    };

    template<typename T>
    std::ostream &operator<<(std::ostream &os, ArrayList<T> &list) {
        for (auto value : list) {
            os << value << ",";
        }
        return os << "\b";
    }
}

#endif //HELLOWORLD_ARRAYLIST_H
