
#include "min_heap.h"

template <typename T> 
MinHeap<T>::MinHeap(int capacity)
{
    heap = new T*[size];
    this.cap = cap;
}

template <typename T> 
MinHeap<T>::~MinHeap()
{
    if(heap)
        delete[] heap;
}

template <typename T>
void MinHeap<T>::insert(T* item)
{
    heap[size++] = item;
}

template <typename T>
void MinHeap<T>::pop()
{
    if(size > 0){
        size --;
        heap[0] = heap[size];
        heap[size] = nullptr;
        heapify(0);
    }
}

template <typename T>
void MinHeap<T>::makeHeap()
{
    for(int i = size/2; i >= 0; i--){
        int min = i;

        int left = MH_LEFT(i);
        int right = MH_RIGHT(i);
        if(left < size && heap[left]->kval < heap[i]->kval)
            min = left;
        if(right < size && heap[right]->kval < heap[min]->kval)
            min = right;

        if(min != i){
            T *tmp;
            tmp = heap[i];
            heap[i] = heap[min];
            heap[min] = tmp;
        }
    }
}

template <typename T>
void MinHeap<T>::heapify(int i)
{
    int min = i;
    int left = MH_LEFT(i);
    int right = MH_RIGHT(i);
    if(left < size && heap[left]->kval < heap[min]->kval){
        min = left;
    }
    if(right < size && heap[right]->kval < heap[min]->kval){
        min = right;
    }

    if(min != i){
        T *tmp;
        tmp = heap[i];
        heap[i] = heap[min];
        heap[min] = tmp;
        heapify(min);
    }
}

template <typename T>
void MinHeap<T>::heapify(T *node)
{
    if(node == nullptr && size > 0){
        size--;
        node = heap[size];
        heap[size] = nullptr;
    }
    heap[0] = node;
    heapify(0);
}
