#include "ListForHash.c"

struct HashTable {
	struct List** words;
	size_t size;
	size_t (*hashF) (char* word);
};

struct HashTable* createTable(size_t (*hashF) (char* word), size_t n);

void addWord(struct HashTable* table, char *word);

void deleteWord(struct HashTable* table, char *word);

size_t getData(struct HashTable* table, char *word);

void setData(struct HashTable*, char* word, size_t val);

void freeTable(struct HashTable* table);

void statistics(struct HashTable* table);