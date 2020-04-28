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

#endif // _MIN_HEAP_H_
