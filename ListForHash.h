#include <stddef.h>
#define Max_Word_Len 25

struct Node {
	size_t data;
	char word[Max_Word_Len];
	struct Node* next;
};

struct List {
	struct Node* head;
	struct Node* tail;
	size_t length;
};

struct List* createList();

struct Node* createNode(size_t val, char* word);

void insertB(struct List* list, struct Node* node);

void insertM(struct List* list, struct Node* after, struct Node* newNode);

struct Node* getN(struct List* list, size_t n);

void deleteNode(struct List* list, struct Node* toDelete);

void freeList(struct List* list);

void printList(struct List* list);

void printNode (struct List* list, size_t n);

struct Node* findInList(struct List* list, char *word);