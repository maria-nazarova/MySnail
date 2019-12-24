#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "List.h"

struct List* createList() {
	struct List* list = malloc(sizeof(struct List));
	if(list == NULL) {
		return NULL;
	}
	list -> head = NULL;
	list -> tail = NULL;
	list -> length = 0;
	return list;
}

struct Node* createNode(int val) {
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	if (node == NULL) {
		return NULL;
	}
	node -> data = val;
	node -> next = NULL;
	return node;
}

void insertB(struct List* list, struct Node* node) {
	node -> next = list -> head;
	list -> head = node;
	list -> length++;
	if (list -> length == 1) {
		list -> tail = node;
	}
	return;
}

void insertM(struct List* list, struct Node* after, struct Node* newNode) {
	newNode -> next = after -> next;
	after -> next = newNode;
	list -> length++;
	if (list -> tail == after) {
		list -> tail = newNode;
	}
	return;
}

struct Node* getN(struct List* list, size_t n) {
	size_t i = 0;
	struct Node* curr = list -> head;
	while (curr) {
		if (i == n) {
			return curr;
		}
		curr = curr -> next;
		i++;
	}
	return NULL;
}

void deleteNode(struct List* list, struct Node* toDelete) {
	struct Node* curr = list -> head;
	while (curr) {
		if ((curr -> next) == toDelete) {
			curr -> next = curr -> next -> next;
			free(toDelete);
			return;
		}
		curr = curr -> next;
	}
	return;
}

void freeList(struct List* list) {
	struct Node* curr = list -> head;
	while (curr) {
		struct Node* tmp = curr;
		curr = curr -> next;
		free(tmp);
	}
	list -> head = NULL;
	list -> tail = NULL;
	list -> length = 0;
	return;
}

_Bool findCycle(struct List* list) {
	struct Node* node1 = list -> head;
	struct Node* node2 = node1;
	while (node1 -> next && node2 -> next) {
		node1 = node1 -> next;
		node2 = node2 -> next -> next;
		if (node1 == node2) {
			return 1;
		}
	}
	return 0;
}

void createCycle(struct List* list, struct Node* node) {
	if (list -> length < 2) {
		printf("Cannot create a cycle\n");
	}
	
	if (findCycle(list)) {
		printf("You already have a cycle\n");
		return;
	}
	
	struct Node* node1 = node;
	while (node1 -> next) {
		node1 = node1 -> next;
	}
	node1 -> next = node;
	return;
}

void printList(struct List* list) {
	struct Node* curr = list -> head;
	while (curr != NULL) {
		printf("%d ", curr -> data);
		curr = curr -> next;
	}
	printf("\n");
}

void printNode (struct List* list, size_t n) {
		struct Node* node = getN(list, n);
		printf("%d\n", node -> data);

}





