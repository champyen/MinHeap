#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <memory>
using namespace std;

#define MH_LEFT(n) (((n+1)*2) - 1)
#define MH_RIGHT(n) ((n+1)*2)

template <typename T>
class MinHeap
{
public:
    MinHeap(int);
    ~MinHeap();
    shared_ptr<T> getMin() { return heap[0]; }
    bool insert(shared_ptr<T>);
    int pop(shared_ptr<T>);
    void makeHeap();
    void heapify(int);

private:
    shared_ptr<T>* heap = nullptr;
    int cap = 0;
    int size = 0;
};

template <typename T>
MinHeap<T>::MinHeap(int capacity)
{
    heap = new shared_ptr<T>[capacity];
    cap = capacity;
}

template <typename T>
MinHeap<T>::~MinHeap()
{
    if(heap)
        delete[] heap;
}

template <typename T>
bool MinHeap<T>::insert(shared_ptr<T> item)
{
    if(size < cap){
        heap[size++] = item;
        return true;
    }
    return false;
}

template <typename T>
void MinHeap<T>::makeHeap()
{
    for(int i = size/2; i >= 0; i--){
        heapify(i);
    }
}

template <typename T>
void MinHeap<T>::heapify(int i)
{
    int min = i;
    int left = MH_LEFT(i);
    int right = MH_RIGHT(i);
    if(left < size){
        if(heap[left]->kval < heap[min]->kval)
            min = left;
    }
    if(right < size){
        if(heap[right]->kval < heap[min]->kval)
            min = right;
    }

    if(min != i){
        shared_ptr<T>tmp;
        tmp = heap[i];
        heap[i] = heap[min];
        heap[min] = tmp;
        heapify(min);
    }
}

template <typename T>
int MinHeap<T>::pop(shared_ptr<T>node)
{
    if(node == nullptr && size > 0){
        size--;
        node = heap[size];
        heap[size] = nullptr;
    }
    heap[0] = node;
    heapify(0);
    return size;
}

#endif // _MIN_HEAP_H_
