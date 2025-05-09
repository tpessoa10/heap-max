#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int leftIdx = left(index);
        int rightIdx = right(index);
        int largest = index;

        if (leftIdx < heap.size() && heap[leftIdx] > heap[largest])
            largest = leftIdx;

        if (rightIdx < heap.size() && heap[rightIdx] > heap[largest])
            largest = rightIdx;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int i)   { return (i - 1) / 2; }
    int left(int i)     { return 2 * i + 1; }
    int right(int i)    { return 2 * i + 2; }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void removeMax() {
        if (heap.empty()) {
            std::cout << "Heap vazio.\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() const {
        if (!heap.empty())
            return heap[0];
        throw std::runtime_error("Heap vazio.");
    }

    void printHeap() const {
        for (int val : heap)
            std::cout << val << " ";
        std::cout << "\n";
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(1);

    std::cout << "Heap atual: ";
    heap.printHeap();

    std::cout << "Maximo: " << heap.getMax() << "\n";

    heap.removeMax();
    std::cout << "Apos remover o maximo: ";
    heap.removeMax();
    std::cout << "Apos remover o maximo novamente";
    heap.printHeap();

    return 0;
}