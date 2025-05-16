#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> MaxHeap;

void heapify(MaxHeap &heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;
    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

void buildHeap(MaxHeap &heap)
{
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, i);
}

void insert(MaxHeap &heap, int key)
{
    heap.push_back(key);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(const MaxHeap &heap)
{
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    MaxHeap heap = {3, 1, 6, 5, 2, 4};

    buildHeap(heap);

    cout << "Max-Heap array: ";
    printHeap(heap);
    cout << "Maximum element: " << heap[0] << endl;

}