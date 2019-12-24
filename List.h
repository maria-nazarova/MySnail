
struct Node {
	int data;
	struct Node* next;
};

struct List {
	struct Node* head;
	struct Node* tail;
	size_t length;
};

struct List* createList();

struct Node* createNode(int val);

void insertB(struct List* list, struct Node* node);

void insertM(struct List* list, struct Node* after, struct Node* newNode);

struct Node* getN(struct List* list, size_t n);

void deleteNode(struct List* list, struct Node* toDelete);

void freeList(struct List* list);

_Bool findCycle(struct List* list);

void createCycle(struct List* list, struct Node* node);

void printList(struct List* list);

void printNode (struct List* list, size_t n);




