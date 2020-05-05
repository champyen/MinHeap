#include <stdio.h>
#include "min_heap.h"

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

#define TEST_SIZE   16

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

    for(int i = 0; i < 128; i++){
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
