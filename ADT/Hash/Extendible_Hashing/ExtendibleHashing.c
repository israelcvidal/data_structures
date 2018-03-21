#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "ExtendibleHashing.h"
#include "Bucket.h"
#include "HashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


ExtendibleHashing* createExtendibleHashing(int n, int bucketSize){
    ExtendibleHashing* extendibleHashing = (ExtendibleHashing*)malloc(sizeof(ExtendibleHashing));
    extendibleHashing->numberOfKeys = n;
    extendibleHashing->bucketSize = bucketSize;
    extendibleHashing->maxPrefix = strlen(getBin(n, NULL));
    extendibleHashing->prefixSize = 1;
    extendibleHashing->hashMaps = (HashMap**)malloc(sizeof(HashMap*)*2);

    for (int i = 0; i < 2; ++i){
        char* key = (char*)&i;
        Bucket* bucket = createBucket(bucketSize);
        extendibleHashing->hashMaps[i] = createHashMap(key, bucket);
    }

    return extendibleHashing;
}

void insertExtendibleHashing(ExtendibleHashing* extendibleHashing, int key){
    char* binaryKey = getBin(key, &extendibleHashing->prefixSize);
    int found = 0;
    int size = sizeof(extendibleHashing->hashMaps);
    for(int i=0; i<size; i++){
        if(extendibleHashing->hashMaps[i]->key == binaryKey){
            found = 1;
            break;
        }
    }
    if(!found){
        printf("KEY NOT FOUND!\n");
        exit(EXIT_FAILURE);
    }




}

LinkedList* searchExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
void removeExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
void freeExtendibleHashing(ExtendibleHashing* extendibleHashing);
int getBucket(ExtendibleHashing* extendibleHashing, int key);
void printExtendibleHashing(ExtendibleHashing* extendibleHashing);

char* getBin(int number, void* n){
    char* buffer = int2bin(number);
    char* nBits = NULL;
    int nInt;
    int len = strlen(buffer);
    if(n != NULL){
        nInt = *(int*)n;
        if( nInt <= len){
            nBits = malloc(sizeof(char)*nInt);
            int i = 0;
            for(int j = len - nInt; j<= len; j++){
                nBits[i] = buffer[j];
                i++;
            }
        }
        else{
            printf("n is too big!\n");
            EXIT_FAILURE;
        }
    }
    else{
        int i = 0;
        int j = 0;
        while(buffer[j] == '0'){
            j++;
        }

        nBits = malloc(sizeof(char)*(len-j));
        for(; j<= len; j++){
            nBits[i] = buffer[j];
            i++;
        }
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
