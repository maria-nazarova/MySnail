#include <stdio.h>

int main() {
	int x = 0x12345678;
	int *p = &x;
	printf("%x %x %x %x = %x\n", *((char*) p), *((char*) p + 1), *((char*) p + 2), *((char*) p + 3), x);
	if (x % (1 << 8) == *((char*) p)) {
		printf("You have a little-endian platform\n\n");
	}
	if (x % (1 << 8) == *((char*) p + 3)) {
		printf("You have a big-endian platform\n\n");
	}
	
	union myU {
		int x;
		char a[4];
	} y;
	y.x = 0x17654321;
	printf("%x %x %x %x = %x\n", y.a[0], y.a[1], y.a[2], y.a[3], y.x);
	if (y.x % (1 << 8) == y.a[0]) {
		printf("You have a little-endian platform\n\n");
	}
	if (x % (1 << 8) == y.a[3]) {
		printf("You have a big-endian platform\n\n");
	}
	return 0;
}
