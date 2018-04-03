#include <stdlib.h>
#include <stdio.h>
#include "Set.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    int n = 4;
    char* charElements[] = {"oi", "meu nome", "eh", "israel"};
    int index = rand() % n;

    Set* set1 = createSet(4, charElements);
    Set* set2 = createSet(4, charElements);


    index = rand() % n;
    printf("INSERTING ELEMENT IN SET1: '%s'\n", charElements[index]);
    insertSet(set1, charElements[index]);

    index = rand() % n;
    printf("INSERTING ELEMENT IN SET1: '%s'\n", charElements[index]);
    insertSet(set1, charElements[index]);

    index = rand() % n;
    printf("INSERTING ELEMENT IN SET1: '%s'\n", charElements[index]);
    insertSet(set1, charElements[index]);

    printf("SET1:\n");
    printSet(set1);

    index = rand() % n;
    printf("INSERTING ELEMENT IN SET2: '%s'\n", charElements[index]);
    insertSet(set2, charElements[index]);

    index = rand() % n;
    printf("INSERTING ELEMENT IN SET2: '%s'\n", charElements[index]);
    insertSet(set2, charElements[index]);

    index = rand() % n;
    printf("INSERTING ELEMENT IN SET2: '%s'\n", charElements[index]);
    insertSet(set2, charElements[index]);

    printf("SET2:\n");
    printSet(set2);

    index = rand() % n;
    printf("REMOVING ELEMENT FROM SET2: '%s'\n", charElements[index]);
    removeSet(set2, charElements[index]);

    printf("SET2:\n");
    printSet(set2);

    Set* setUnion = unionSet(set1, set2);
    Set* setInt = intersectionSet(set1, set2);
    Set* setDiff = differenceSet(set1, set2);

    printf("\nSET OPERATIONS:\n");
    printf("UNION:\n");
    printSet(setUnion);
    printf("INTERSECTION:\n");
    printSet(setInt);
    printf("DIFFERENCE:\n");
    printSet(setDiff);

    printf("\n");
    printf("SET1:\n");
    printSet(set1);
    printf("COMPLEMENT OF SET1:\n");
    printSet(complementSet(set1));

    printf("\n");
    printf("IS SET1 == SET2?:\n");
    if(isEqualSet(set1, set2)){
        printf("YES!\n");
    }
    else printf("NO!\n");

    printf("IS SET1 == SET1?:\n");
    if(isEqualSet(set1, set1)){
        printf("YES!\n");
    }
    else printf("NO!\n");


    index = rand() % n;
    printf("IS '%s' IN SET1?:\n", charElements[index]);
    if(isMemberSet(set1, charElements[index])){
        printf("YES!\n");
    }
    else printf("NO!\n");

    printf("IS SET1 SUBSET OF SET1?:\n");
    if(isSubset(set1, set1)){
        printf("YES!\n");
    }
    else printf("NO!\n");

    printf("SIZE OF SET2 IS %d\n", sizeSet(set2));

    printf("SET2:\n");
    printSet(set2);

    printf("FREEING SETs!\n");
    freeSet(set1);
    freeSet(set2);





    return 0;
}
