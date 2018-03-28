#pragma once

typedef struct heap Heap;

struct heap{
    int value;
    Heap* leftChild;
    Heap* rightChild;
};

Heap* createHeap();
Heap* insertHeap(Heap* heap, int value);
Heap* searchHeap(Heap* heap, int value);
Heap* removeHeap(Heap* heap, int value);
Heap* changeValueHeap(Heap* heap, int oldValue, int newValue);
void freeHeap(Heap* heap);






