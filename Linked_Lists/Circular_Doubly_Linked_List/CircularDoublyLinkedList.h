typedef struct circularDoublyLinkedList CircularDoublyLinkedList;

struct circularDoublyLinkedList{
	int inf;
	CircularDoublyLinkedList* next;
	CircularDoublyLinkedList* prev;
};

CircularDoublyLinkedList* create();
CircularDoublyLinkedList* insert(CircularDoublyLinkedList* list, int value);
void printList(CircularDoublyLinkedList* list);
void recursiveAuxPrint(CircularDoublyLinkedList* head, CircularDoublyLinkedList* list);
void recursivePrint(CircularDoublyLinkedList* list);
int empty(CircularDoublyLinkedList* list);
CircularDoublyLinkedList* search(CircularDoublyLinkedList* list, int value);
CircularDoublyLinkedList* removeList(CircularDoublyLinkedList* list, int value);
void updateHeader(CircularDoublyLinkedList* list, CircularDoublyLinkedList* oldHead, CircularDoublyLinkedList* newHead);
CircularDoublyLinkedList* recursiveAuxRemove(CircularDoublyLinkedList* head, CircularDoublyLinkedList* list,  int value);
CircularDoublyLinkedList* recursiveRemove(CircularDoublyLinkedList* list, int value);
void freeList(CircularDoublyLinkedList* list);