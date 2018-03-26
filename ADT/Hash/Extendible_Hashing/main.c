#include "ExtendibleHashing.h"
#include<stdio.h>
#include<string.h>

int main(){
    printf("Creating extendible hash with bucket size %d", 3);
    ExtendibleHashing* eh = createExtendibleHashing(3);
    printf("Inserting keys from %d to %d in extendible hash\n", 1, 7);

    for(int i=0; i<7; i++){
        insertExtendibleHashing(eh, i);
    }

    printf("Printing Hash:\n");
    printExtendibleHashing(eh);

    printf("Removing key %d\n", 3);
    removeExtendibleHashing(eh, 3);

    printf("Printing Hash:\n");
    printExtendibleHashing(eh);

    printf("Searching for key %d\n", 5);
    printf("%s", searchExtendibleHashing(eh, 5) ? "found\n" : "not found\n");

    printf("Free Extendible Hash!\n");
    freeExtendibleHashing(eh);

    return 0;
}

