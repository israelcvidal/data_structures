#include <stdlib.h>
#include <stdio.h>
#include "Set.h"
#include <string.h>

Set* createSet(int numberOfElements, char** elements){
    Set* set = (Set*)malloc(sizeof(Set));
    set->n = numberOfElements;

    set->elements = (char**)malloc((numberOfElements)*sizeof(char*));
    for(int i=0; i<numberOfElements; i++){
        set->elements[i] = elements[i];
    }
    set->bitarray = (char*)malloc(BITNSLOTS(numberOfElements));
    return set;
}

int getIndex(Set* set, char* data){
    int i = 0;
    for(; i<set->n; i++){
        if(strcmp(set->elements[i], data)==0)
            break;
    }
    if(i < set->n)
        return i+1;
    return -1;
}

int insertSet(Set* set, char* data){
    int index = getIndex(set, data);

    if(index >= 0){
        BITSET(set->bitarray, index);
        return 1;
    }
    return 0;
}

int removeSet(Set* set, void* data){
    int index = getIndex(set, data);

    if(index >= 0){
        BITCLEAR(set->bitarray, index);
        return 1;
    }
    return 0;
}

int isValid(Set* set1, Set* set2){
    if(set1->n != set2->n){
        printf("THE UNIVERSE OF THE TWO SETS ARE NOT THE EQUAL!\n");
        return 0;
    }
    for(int i = 0; i<set1->n; i++){
        if(strcmp(set1->elements[i], set2->elements[i]) != 0){
            printf("THE UNIVERSE OF THE TWO SETS ARE NOT THE EQUAL!\n");
            return 0;
        }
    }
    return 1;
}

Set* unionSet(Set* set1, Set* set2){
    if(!isValid(set1, set2))
        return NULL;

    Set* setUnion = createSet(set1->n, set1->elements);

    for(int i = 0; i < BITNSLOTS(set1->n); i++)
        setUnion->bitarray[i] = set1->bitarray[i] | set2->bitarray[i];

    return setUnion;
}

Set* intersectionSet(Set* set1, Set* set2){
    if(!isValid(set1, set2))
        return NULL;

    Set* setInt = createSet(set1->n, set1->elements);

    for(int i = 0; i < BITNSLOTS(set1->n); i++)
        setInt->bitarray[i] = set1->bitarray[i] & set2->bitarray[i];

    return setInt;
}

Set* differenceSet(Set* set1, Set* set2){
    if(!isValid(set1, set2))
        return NULL;

    Set* setDiff = createSet(set1->n, set1->elements);

    for(int i = 0; i < BITNSLOTS(set1->n); i++)
        setDiff->bitarray[i] = set1->bitarray[i] ^ set2->bitarray[i];

    return setDiff;
}

int isMemberSet(Set* set, char* data){
    int index = getIndex(set, data);

    if(index >= 0 && BITTEST(set->bitarray, index))
        return 1;
    return 0;
}

int isSubset(Set* set1, Set* set2){
    if(isEqualSet(unionSet(set1, set2), set2))
        return 1;
    return 0;
}

int isEqualSet(Set* set1, Set* set2){
    Set* setDiff = differenceSet(set1, set2);

    for(int i = 1; i <= set1->n; i++){
        if(BITTEST(setDiff->bitarray, i))
            return 0;
    }
    return 1;
}

Set* complementSet(Set* set){
    Set* fullBitsSet = createSet(set->n, set->elements);

    for(int i = 1; i <= set->n; i++)
        BITSET(fullBitsSet->bitarray, i);

    return differenceSet(set, fullBitsSet);
}

int sizeSet(Set* set){
    int count = 0;

    for(int i= 1; i<=set->n; i++){
        if(BITTEST(set->bitarray, i))
            count++;
    }
    return count;
}

void freeSet(Set* set){
    free(set->bitarray);
    free(set->elements);
    free(set);
}

void printSet(Set* set){
    for(int i= 1; i<=set->n; i++){
        if(BITTEST(set->bitarray, i))
            printf("%s\t", set->elements[i-1]);
    }
    printf("\n");
}
