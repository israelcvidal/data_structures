typedef struct doublyLinkedList DoublyLinkedList;

struct doublyLinkedList{
	int inf;
	DoublyLinkedList* next;
	DoublyLinkedList* prev;
};

DoublyLinkedList* create();
DoublyLinkedList* insert(DoublyLinkedList* list, int value);
void printList(DoublyLinkedList* list);
void recursivePrint(DoublyLinkedList* list);
void reversePrint(DoublyLinkedList* list);
int empty(DoublyLinkedList* list);
DoublyLinkedList* search(DoublyLinkedList* list, int value);
DoublyLinkedList* removeList(DoublyLinkedList* list, int value);
DoublyLinkedList* recursiveRemove(DoublyLinkedList* list, int value);
void freeList(DoublyLinkedList* list);
int equal(DoublyLinkedList* list1, DoublyLinkedList* list2);