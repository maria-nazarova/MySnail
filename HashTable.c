#include "HashTable.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

struct HashTable* createTable(size_t (*hashF) (char* word), size_t n) {
	struct HashTable* table = malloc(sizeof(struct HashTable));
	if (!table) {
		printf("Cannot create a hashtable");
		return NULL;
	}
	
	table -> size = n;
	table -> hashF = hashF;
	table -> words = malloc(n * sizeof(struct List*));
	if (!table -> words) {
		printf("Cannot create a hashtable");
		return NULL;
	}
	for (int i = 0; i < n; ++i) {
		table -> words[i] = createList();
		if (!table -> words[i]) {
			printf("Cannot create a hashtable");
			return NULL;
		}
	}
	return table;
}
	
void addWord(struct HashTable* table, char *word, size_t hash) {
	struct Node* node = findInList(table -> words[hash], word);
	if (!node) {
		insertB(table -> words[hash], createNode(0, word));
	}
	return;
}
	
void deleteWord(struct HashTable* table, char *word) {
	size_t hash = table -> hashF (word);
	struct Node* node = findInList(table -> words[hash], word);
	if (node) {
		deleteNode(table -> words[hash], node);
	}
	return;
}

size_t getData(struct HashTable* table, char *word) {
	size_t hash = table -> hashF (word);
	struct Node* node = findInList(table -> words[hash], word);
	if (!node) {
		return 0;
	} else {
		return node -> data;
	}
}

void setData(struct HashTable* table, char* word, size_t val) {
	size_t hash = table -> hashF (word);
	addWord(table, word, hash);
	struct Node* node = findInList(table -> words[hash], word);
	node -> data = val;
	
	return;
}

void freeTable(struct HashTable* table) {
	for (int i = 0; i < table -> size; ++i) {
		freeList(table -> words[i]);
	}
	free(table -> words);
	free(table);
	return;
}

void statistics(struct HashTable* table) {
	size_t elem = 0, cells = 0, avLen = 0, minLen = table -> size, maxLen = 0;
	for (int i = 0; i < table -> size; ++i) {
		size_t len = (table -> words[i]) -> length;
		if (len != 0) {
			cells++;
		}
		elem += len;
		if (minLen > len && len != 0) {
			minLen = len;
		}
		if (maxLen < len) {
			maxLen = len;
		}
	}
	avLen = elem / cells;
	printf("Number of not empty cells = %d\n", cells);
	printf("Number of elements = %d\n", elem);
	printf("Average length of list = %d\n", avLen);
	printf("Minimum length of list = %d\n", minLen);
	printf("Maximum length of list = %d\n", maxLen);
}


