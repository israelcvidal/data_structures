#pragma once

//bit operations found in http://c-faq.com/misc/bitsets.html

#include <limits.h>		/* for CHAR_BIT */

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

typedef struct set Set;

struct set{
    int n;
    char** elements;
    char* bitarray;
};

Set* createSet(int numberOfElements, char** elements);
int insertSet(Set* set, char* data);
int removeSet(Set* set, void* data);
Set* unionSet(Set* set1, Set* set2);
Set* intersectionSet(Set* set1, Set* set2);
Set* differenceSet(Set* set1, Set* set2);
int isMemberSet(Set* set, char* data);
int isSubset(Set* set1, Set* set2);
int isEqualSet(Set* set1, Set* set2);
Set* complementSet(Set* set);
int sizeSet(Set* set);
void freeSet(Set* set);
int getIndex(Set* set, char* data);
void printSet(Set* set);
