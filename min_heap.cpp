#include <stdio.h>
#include "min_heap.h"

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

#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Node
{
public:
	Node(int key) {kval = key;}
	~Node() {};
	unsigned int kval;
};

#define TEST_SIZE	16

int main(void)
{
	MinHeap<Node> heap(TEST_SIZE);
	srand(time(NULL));
	for(int i = 0; i < TEST_SIZE; i++){ 
		shared_ptr<Node> n = make_shared<Node>(rand()&0xFF);
		printf("%u\n", n->kval);
		heap.insert(n);
	}
	heap.makeHeap();
	printf("\n");

	for(int i = 0; i < 1024; i++){
		shared_ptr<Node> n = heap.getMin();
		int min = n->kval;

		n = make_shared<Node>((rand()&0xFF) + min);
		heap.pop(n);
		printf("%u %u\n", min, n->kval);
	}

	printf("\n");
	for(int i = 0; i < TEST_SIZE; i++){
		shared_ptr<Node>n = heap.getMin();
		heap.pop(nullptr);
		printf("%u\n", n->kval);
	}

	return 0;
}

#endif
