#pragma once

typedef struct heap Heap;

struct heap{
    int max;
    int position;
    float* priority;
};

Heap* createHeap(int max);
void insertHeap(Heap* heap, int value);
int searchHeap(Heap* heap, int value);
float removeHeap(Heap* heap);
void changePriorityHeap(Heap* heap, float oldValue, float newValue);
void freeHeap(Heap* heap);
void heapify(Heap* heap, int position);
//void fixAbove(Heap* heap, int position);
//void fixBelow(Heap* heap, int position);
void swap(float* priority, int pos1, int pos2);
void buildHeap(Heap* heap);
void printHeap(Heap* heap);



