#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

Heap* createHeap(int max){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->max = max;
    heap->position = 0;
    heap->priority = (float*)malloc(sizeof(float)*max);

    return heap;
}

void insertHeap(Heap* heap, int value){
    if(heap->position < heap->max){
        heap->priority[heap->position++] = value;
        buildHeap(heap);
    }
    else{
        printf("HEAP IS FULL!\n");
    }

}

void swap(float* priority, int pos1, int pos2){
    float aux = priority[pos1];
    priority[pos1] = priority[pos2];
    priority[pos2] = aux;
}



float removeHeap(Heap* heap){
    if(heap->position == 0){
        printf("HEAP IS EMPTY!\n");
        return -1;
    }

    float max_value = heap->priority[0];
    heap->priority[0] = heap->priority[--heap->position];
    heapify(heap, 0);

    return max_value;
}


void heapify(Heap* heap, int position){
    int leftChild = 2*position + 1;
    int rightChild = leftChild + 1;
    int maxValue = position;

    if(leftChild < heap->position && heap->priority[leftChild] > heap->priority[position])
        maxValue = leftChild;
    if(rightChild < heap->position && heap->priority[rightChild] > heap->priority[maxValue])
        maxValue = rightChild;
    if(maxValue != position){
        swap(heap->priority, maxValue, position);
        heapify(heap, maxValue);
    }
}

void buildHeap(Heap* heap){
    for(int i= heap->position-1; i>=0; i--){
        heapify(heap, i);
    }
}

void changePriorityHeap(Heap* heap, float oldValue, float newValue){
    int position = searchHeap(heap, oldValue);
    if(position>=0){
        heap->priority[position] = newValue;
        buildHeap(heap);
    }
    else{
        printf("%f IS NOT IN THE HEAP TO BE CHANGED!\n", oldValue);
    }

}

int searchHeap(Heap* heap, int value){
    for(int i=0; i<heap->position; i++){
        if(heap->priority[i] == value){
            return i;
        }
    }
    return -1;
}

void freeHeap(Heap* heap){
    free(heap->priority);
    free(heap);
}

void printHeap(Heap* heap){
    printf("HEAP:\n");
    for(int i=0; i<heap->position; i++){
        printf("%f ", heap->priority[i]);
    }
    printf("\n");
}

