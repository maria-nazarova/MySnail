#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mman.h"
#include <fcntl.h>
#include <sys/stat.h>


int myStrCmp(const void* ptr1, const void* ptr2) {
	char* str1 = * (char**)ptr1, * str2 = * (char**)ptr2;
	return strcmp(str1, str2);
}

void copyStrAddr(char **strings, char *inp) {
    size_t i = 0, j = 0, k = 0;
    while (inp[i]) {
        if (inp[i] == '\n') {
            strings[j] = &inp[k];
            j++;
			k = i + 1;
        }
        i++;
    }
	return;
}

int main() {
    int fileInDes = open("Text.txt", O_RDWR, 0);
    if (fileInDes < 0) {
        printf("Cannot open input file");
        exit(1);
    }
    FILE* fileOut = fopen("out.txt", "w");
    if (fileOut == NULL) {
        printf("Cannot open output file");
        exit(1);
    }


    struct stat info;
	fstat(fileInDes, &info);
	size_t size = info.st_size, numS = 0;
    char* inp = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fileInDes, 0);
	if (inp == MAP_FAILED) {
		printf("Cannot map file to memory");
		exit(1);
	}
    int len = strlen(inp);
	
    for (size_t i = 0; i < len; i++) {
        if (inp[i] == '\n') {
            numS++;
        }
    }


    char **str = (char**)malloc(numS * sizeof(char*));
    if (str == NULL) {
        printf("Cannot allocate memory");
        exit(1);
    }

    copyStrAddr(str, inp);
    qsort(str, numS, sizeof(char*), myStrCmp);

    for (size_t i = 0; i < numS; i++) {
        size_t j = 0;
        while (str[i][j] != '\n') {
            fprintf(fileOut,"%c", str[i][j]);
            j++;
        }
		fprintf(fileOut,"%c", '\n');
    }

    close(fileInDes);
    fclose(fileOut);
    free(str);
    munmap(inp, len);
    return 0;
}