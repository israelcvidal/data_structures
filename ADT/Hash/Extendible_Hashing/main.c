#include "ExtendibleHashing.h"
#include<stdio.h>
#include<string.h>

int main(){
    ExtendibleHashing* eh = createExtendibleHashing(3);
    insertExtendibleHashing(eh, 1);
    insertExtendibleHashing(eh, 2);
    insertExtendibleHashing(eh, 3);
    insertExtendibleHashing(eh, 4);
    insertExtendibleHashing(eh, 5);
    insertExtendibleHashing(eh, 6);
    insertExtendibleHashing(eh, 7);

    printExtendibleHashing(eh);
    return 0;
}

