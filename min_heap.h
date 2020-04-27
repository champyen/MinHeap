#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#define MH_LEFT(n) (((n+1)*2) - 1)
#define MH_RIGHT(n) ((n+1)*2)

template <typename T>
class MinHeap
{
public:
    MinHeap(int);
    ~MinHeap();
    T* getMin() { return heap[0]; }
    bool insert(T*);
    int pop(T*);
    void makeHeap();
    void heapify(int);

private:
    T** heap = nullptr;
    int cap = 0;
    int size = 0;
};

#endif // _MIN_HEAP_H_
