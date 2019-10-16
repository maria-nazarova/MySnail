#include <stdio.h>
#include <stdlib.h>

size_t maxSize = 250;

int main(){
	int n;
	unsigned int f[maxSize];
	f[0] = 1;
	f[1] = 1;
	scanf("%d", &n);
	if (n < 0) {
		printf("Incorrect value");
	} else {
		for (int i = 2; i <= n; i++){
			f[i] = f[i - 1] + f[i - 2];
		}
		printf("%u", f[n]);
	}
}
