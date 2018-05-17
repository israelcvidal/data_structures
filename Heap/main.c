#include "Heap.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
    int n = 5;
    float value;

    srand(time(NULL));


    printf("CREATING HEAP WITH SIZE %d\n", n);
    Heap* heap = createHeap(5);

    for(int i=0; i<n; i++){
        value = rand() % 20;

        printf("INSERTING IN HEAP: %f \n", value);
        insertHeap(heap, value);
    }

    printHeap(heap);

    float newValue = rand() % 20;

    printf("CHANGING VALUE %f TO %f\n", value, newValue);
    changePriorityHeap(heap, value, newValue);

    printHeap(heap);

    value = rand() % 20;
    printf("SEACHING IN HEAP: %f\n", value);
    int position = searchHeap(heap, value);

    if(position>=0){
        printf("ELEMENT FOUND AT POSITION %d\n", position);
    }
    else{
        printf("ELEMENT NOT FOUND IN HEAP!\n");
    }

    for(int i=0; i<n; i++){
        printf("REMOVING FROM HEAP: %f \n", removeHeap(heap));
    }

    return 0;
}
