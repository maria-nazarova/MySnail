#include <stdio.h>
#include <stdlib.h>

size_t maxSize = 250;

int main() {
	int n;
	unsigned int fib0, fib1, fib2;
	fib0 = 1;
	fib1 = 1;
	scanf("%d", &n);
	if (n < 0) {
		printf("Incorrect value");
	} else {
		for (int i = 2; i <= n; i++) {
			fib2 = fib1 + fib0;
			fib0 = fib1;
			fib1 = fib2;
		}
		printf("%lu", fib1);
	}
}