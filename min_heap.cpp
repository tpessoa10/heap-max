#include <vector>
#include <iostream>
#include <climits>

using namespace std;

typedef vector<int> MinHeap;

void heapify(MinHeap &heap, int i)
{
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < heap.size() && heap[esq] < heap[menor])
        menor = esq;
    if (dir < heap.size() && heap[dir] < heap[menor])
        menor = dir;

    if (menor != i)
    {
        swap(heap[i], heap[menor]);
        heapify(heap, menor);
    }
}

void buildHeap(MinHeap &heap)
{
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) // os ultimos n/2 elementos já são folhas
        heapify(heap, i);
}

// diferença para o heapify: funciona de baixo para cima
void insert(MinHeap &heap, int key)
{
    heap.push_back(key);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// troca o elemento na raiz do heap com o último elemento e remove o último elemento, depois aplica o heapify
int extractMin(MinHeap &heap)
{
    if (heap.size() == 0)
        return INT_MAX;

    if (heap.size() == 1)
    {
        int root = heap[0];
        heap.pop_back();
        return root;
    }

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, 0);

    return root;
}

int altura(const MinHeap &heap)
{
    int h = 0;
    int n = heap.size();
    while (n > 1)
    {
        n /= 2;
        h++;
    }
    return h;
}

vector<int> heapsort(const MinHeap &heap)
{
    vector<int> sorted;
    MinHeap temp = heap;

    while (!temp.empty())
    {
        sorted.push_back(extractMin(temp));
    }

    return sorted;
}

void printHeap(const MinHeap &heap)
{
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    MinHeap heap = {3, 1, 6, 5, 2, 4};
    insert(heap, 9);
    insert(heap, 12);

    buildHeap(heap);

    cout << "Min-Heap array: ";
    printHeap(heap);
    cout << "Minimum element: " << heap[0] << endl;

    cout << "Height of the heap: " << altura(heap) << endl;

    cout << "Sorted array: ";
    vector<int> sorted = heapsort(heap);
    printHeap(sorted);

    return 0;
}