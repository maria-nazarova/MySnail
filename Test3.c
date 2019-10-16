#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	_Bool count[256];
	int n, seq[256], a, k = 0;
	memset(count, 0, 256 * sizeof(_Bool));
	memset(seq, 0, 256 * sizeof(int));
	printf("Enter the number of numbers\n");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a);
		if (count[a] == 0) {
			seq[k] = a;
			count[a] = 1;
			k++;
		}
	}
	for (int i = 0; i < k; ++i) printf("%d ",seq[i]);
}