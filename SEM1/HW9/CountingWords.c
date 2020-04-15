#include "HashTable.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const size_t Table_Size = 50000;
const char punct[] = {'.',',',':',';','\'','\"','!','(',')','?',0};

size_t hashConst(char* word) {
	return 5;
}

size_t hashSum(char* word) {
	size_t hash = 0;
	while (*word) {
		hash += (unsigned char) *word;
		word++;
	}
	return hash % Table_Size;
}

size_t hashOK(char* word) {
	size_t hash = 0;
	while (*word) {
		hash += (unsigned char)(*word);
		hash += (hash << 10);
		hash ^= (hash >> 6);
		word ++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash % Table_Size;
}

void noPunct(char* word){
	size_t len = strlen(word);
	if (strchr(punct, word[len - 1])) {
		word[len - 1] = 0;
	}
	return;
}

void upperCase(char* word) {
	while (*word) {
		*word = toupper((int)*word);
		word++;
	}
	return;
}

int main() {
	size_t (*hashF[]) (char * word) = {hashConst, hashSum, hashOK};
	size_t numT = sizeof(hashF) / sizeof(hashF[0]);
	struct HashTable* table;
	char word[Max_Word_Len];
	clock_t beg, end;
	for (int i = 0; i < numT; ++i) {
		beg = clock();
		table = createTable(hashF[i], Table_Size);
		if (!table) {
			printf("Failed creating a table");
			break;
		}
		FILE* fileP = fopen("Onegin.txt", "r");
		if (!fileP) {
			printf("Cannot open input file");
		}
		fscanf(fileP, "%s", word);
		while (*word) {
			noPunct(word);
			upperCase(word);
			if (*word) {
				setData(table, word, getData(table, word) + 1);
			}
			*word = 0;
			fscanf(fileP, "%s", word);
		}
		end = clock();
		statistics(table);
		freeTable(table);
		fclose(fileP);
		printf("Time for hash%d = %3.5f\n\n", i, (float) (end - beg) / CLOCKS_PER_SEC);
	}
	return 0;
}

