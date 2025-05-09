#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int pai(int i)  { return (i - 1) / 2; }
    int esq(int i)    { return 2 * i + 1; }
    int dir(int i)   { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[pai(i)] > heap[i]) {
            swap(heap[i], heap[pai(i)]);
            i = pai(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int l = esq(i);
        int r = dir(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void inserir(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int getMin() const {
        if (heap.empty()) return INT_MIN;
        return heap[0];
    }

    int extrairMin() {
        if (heap.empty()) return INT_MIN;
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    void print() const {
        cout << "Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

// Exemplo de uso
int main() {
    MinHeap heap;

    heap.inserir(10);
    heap.inserir(4);
    heap.inserir(15);
    heap.inserir(20);
    heap.inserir(0);

    heap.print();

    cout << "Menor elemento: " << heap.getMin() << endl;
    cout << "Extraindo menor: " << heap.extrairMin() << endl;

    heap.print();

    return 0;
}
