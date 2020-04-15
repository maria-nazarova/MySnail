#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t RANGE_MAX = 256;

int main() {
	_Bool count[RANGE_MAX];
	int n, seq[RANGE_MAX], a, k = 0;
	memset(count, 0, RANGE_MAX * sizeof(_Bool));
	memset(seq, 0, RANGE_MAX * sizeof(int));
	printf("Enter the number of numbers\n");
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (count[a] == 0) {
			seq[k] = a;
			count[a] = 1;
			k++;
		}
	}
	
	for (int i = 0; i < k; ++i) {
		printf("%d ", seq[i]);
	}
}
