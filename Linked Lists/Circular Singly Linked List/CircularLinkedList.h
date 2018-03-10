typedef struct circularLinkedList CircularLinkedList;

struct circularLinkedList{
	int inf;
	CircularLinkedList* next;
};

CircularLinkedList* create();
CircularLinkedList* insert(CircularLinkedList* list, int value);
void printList(CircularLinkedList* list);
void recursiveAuxPrint(CircularLinkedList* head, CircularLinkedList* list);
void recursivePrint(CircularLinkedList* list);
int empty(CircularLinkedList* list);
CircularLinkedList* search(CircularLinkedList* list, int value);
CircularLinkedList* removeList(CircularLinkedList* list, int value);
void updateHeader(CircularLinkedList* list, CircularLinkedList* oldHead, CircularLinkedList* newHead);
CircularLinkedList* recursiveAuxRemove(CircularLinkedList* head, CircularLinkedList* list,  int value);
CircularLinkedList* recursiveRemove(CircularLinkedList* list, int value);
void freeList(CircularLinkedList* list);