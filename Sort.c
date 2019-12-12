#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>

const size_t itsbig = 1000000;
int magicNumber = 823;

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void countingSort(int *b, size_t n) {
	int *count = malloc(itsbig * 4);
	if (count == NULL) {
		printf("Failed allocating memory");
		return;
	}
	memset(count, 0, itsbig * 4);
	for (size_t i = 0; i < n; i++) {
		count[b[i]]++;
	}
	size_t j = 0;
	for (size_t i = 0; i < itsbig; i++) {
		while (count[i]) {
			b[j++] = i;
			count[i]--;
		}
	}
}

int findMin(int *b, size_t n) {
	int Min = b[0], nMin = 0;
	for (size_t i = 1; i < n; ++i) {
		if (b[i] < Min) {
			Min = b[i];
			nMin = i;
		}
	}
	return nMin;
}

void insertionSort(int *b, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		size_t t = findMin(b + i, n - i) + i;
		swap(&b[t], &b[i]);
	}
	return;
}

void quickSortR(int *b, size_t l, size_t r) {
	if ((l + 1) == r || l == r)
		return;
	
	size_t m = (r - l) / 2 + l, k = 0;
	swap(&b[l], &b[m]);
	size_t i = l + 1;
	while (i < (r - k)) {
		if (b[i] > b[i - 1]) {
			swap (&b[i], &b[r - (++k)]);
		} else {
			swap (&b[i], &b[i - 1]);
			i++;
		}
	}
	quickSortR(b, l, i - 1);
	quickSortR(b, i, r);
}

void random(int *b, size_t n) {
	srand(magicNumber);
	for (size_t i = 0; i < n; ++i){
		b[i] = rand() % itsbig;
	}
}

void quickSort(int *b, size_t n) {
	quickSortR(b, 0, n);
}

int main() {
	size_t n[] = {5, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	void (*sorts[])(int *, size_t) = {&countingSort, &quickSort, &insertionSort};
	char *names[]= {"N","NlogN", "N^2"};
	clock_t beg, end;
	size_t numS = sizeof(sorts)/sizeof(sorts[0]);
	size_t numN = sizeof(n)/sizeof(n[0]);
	int *data = malloc(n[numN - 1] * sizeof(int));
	if (data == NULL) {
		printf("Failed allocating memory");
		return 0;
	}
	
	
	for (size_t i = 0; i < numN; ++i){
		printf("Array size = %d\n", n[i]);
		for (size_t j = 0; j < numS; j++) {
			random(data, n[i]);
			beg = clock();
			sorts[j](data, n[i]);
			end = clock();
			printf("O(%s) Time = %3.5f  ", names[j], (float) (end - beg)/CLOCKS_PER_SEC);
		}
	printf("\n\n");
	}
	free(data);
}