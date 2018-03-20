#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "ExtensibleHashing.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


ExtensibleHashing* createHashTable(int n);
void insertHashTable(ExtensibleHashing* extensibleHashing, int key);
LinkedList* searchHashTable(ExtensibleHashing* extensibleHashing, int key);
void removeHashTable(ExtensibleHashing* extensibleHashing, int key);
void freeHashTable(ExtensibleHashing* extensibleHashing);
int getBucket(ExtensibleHashing* extensibleHashing, int key);
void printHashTable(ExtensibleHashing* extensibleHashing);

char* getBits(int number, int n){
    char* buffer = int2bin(number);
    char* nBits = malloc(sizeof(char)*n);
    int len = strlen(buffer);

    if( n <= len){
        int i = 0;
        for(int j = len - n; j<= len; j++){
            nBits[i] = buffer[j];
            i++;
        }
    }
    else{
        printf("n is too big!\n");
        EXIT_FAILURE;
    }
    return nBits;
//    if(strlen(buffer) )
}

//function obtained from: https://www.quora.com/Is-there-a-function-in-C-that-converts-an-integer-into-bits
char* int2bin(int n) {
    // determine the number of bits needed ("sizeof" returns bytes)
    int nbits = sizeof(n) * 8;
    char *s = malloc(nbits+1);  // +1 for '\0' terminator
    s[nbits] = '\0';
    // forcing evaluation as an unsigned value prevents complications
    // with negative numbers at the left-most bit
    unsigned int u = *(unsigned int*)&n;
    int i;
    unsigned int mask = 1 << (nbits-1); // fill in values right-to-left
    for (i = 0; i < nbits; i++, mask >>= 1)
        s[i] = ((u & mask) != 0) + '0';
    return s;
}
