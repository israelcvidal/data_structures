#include "ExtendibleHashing.h"
#include<stdio.h>
#include<string.h>

int main(){
    ExtendibleHashing* eh = createExtendibleHashing(2, 1);
    insertExtendibleHashing(eh, 2);
    insertExtendibleHashing(eh, 8);
    insertExtendibleHashing(eh, 16);
    insertExtendibleHashing(eh, 3);
    printExtendibleHashing(eh);
    insertExtendibleHashing(eh, 4);
    printExtendibleHashing(eh);
    return 0;
}

