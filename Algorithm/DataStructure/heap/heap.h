#ifndef ZERO_HEAP_H
#define ZERO_HEAP_H

typedef struct PriorityQueue {
    int capacity;
    int size;
    int elements[];
} PQ;

#define PARENT(i) (i>=1?(i-1)/2:0)
#define LEFT(i)(2*i+1)
#define RIGHT(i)(2*i+2)
#endif //ZERO_HEAP_H
