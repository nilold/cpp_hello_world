#ifndef HELLOWORLD_HEAP_H
#define HELLOWORLD_HEAP_H

#include <vector>
#include <stdexcept>

namespace nilolib {
    template<typename T>
    class Heap {
    private:
        std::vector<T> heap;

        void fixHeapAbove(unsigned long index) {
            T newValue = heap[index];
            while (index > 0 && newValue > heap[getParentIndex(index)]) {
                heap[index] = heap[getParentIndex(index)];
                index = getParentIndex(index);
            }

            heap[index] = newValue;
        }

        void fixHeapBelow(unsigned long index, unsigned long lastIndex) {
            while (index <= lastIndex) {
                unsigned long leftIdx = getLeftChildIndex(index);
                unsigned long rightIdx = getRightChildIndex(index);

                unsigned long idxToSwap;

                if (leftIdx <= lastIndex) {
                    if (rightIdx <= lastIndex) {
                        idxToSwap = heap[rightIdx] > heap[leftIdx] ? rightIdx : leftIdx;
                    } else {
                        idxToSwap = leftIdx;
                    }

                    if (heap[index] < heap[idxToSwap]) {
                        T tmp = heap[index];
                        heap[index] = heap[idxToSwap];
                        heap[idxToSwap] = tmp;
                    } else { break; }

                    index = idxToSwap;
                } else { break; }
            }
        }

    public:
        Heap() {}

        Heap(const int &initialSize) {
            heap.reserve(initialSize);
        }

        ~Heap() {}

        static unsigned long getParentIndex(const unsigned long nodeIndex) {
            return (nodeIndex - 1) / 2;
        }

        static unsigned long getLeftChildIndex(const unsigned long nodeIndex) {
            return nodeIndex * 2 + 1;
        }

        static unsigned long getRightChildIndex(const unsigned long nodeIndex) {
            return getLeftChildIndex(nodeIndex) + 1;
        }

        unsigned long getLeftmostIndex() {
            unsigned long index = 0;
            unsigned long newIndex;

            while (index < heap.size()) {
                newIndex = index;
                index = getLeftChildIndex(index);
            }
            return newIndex;
        }

        void insert(const T &value) {
            heap.emplace_back(value);
            fixHeapAbove(heap.size() - 1);
        }

        T remove(const unsigned long &index = 0) {
            T deletedValue = heap[index];

            if (index < heap.size()) {
                heap[index] = heap[heap.size() - 1];
            } else {
                throw std::out_of_range("Index out of range");
            }

            unsigned long parent = heap[getParentIndex(index)];


            if (heap[index] > parent) {
                fixHeapAbove(index);
            } else if (heap[index] < parent) {
                fixHeapBelow(index, heap.size() - 1);
            }

            heap.pop_back();

            return deletedValue;
        }

        void sort() {
            unsigned long lastIdx = heap.size() - 1;

            for (unsigned long i = 0; i < lastIdx; ++i) {
                T tmp = heap[0];
                heap[0] = heap[lastIdx - i];
                heap[lastIdx - i] = tmp;

                fixHeapBelow(0, lastIdx - i - 1);
            }

        }


        T peek() const {
            if (heap.size() > 0) {
                return heap[0];
            }
            throw std::out_of_range("Heap is empty!");
        }

        void printHeap() const {

            for (auto it : heap) {
                std::cout << it << ",";
            }
            std::cout << "\b" << std::endl;
        }


    };
}


#endif //HELLOWORLD_HEAP_H
