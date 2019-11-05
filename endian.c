#include <stdio.h>

int main(){
	int x = 0x12345678;
	int *p = &x;
	printf("%x %x %x %x = %x\n\n", *((char*) p), *((char*) p + 1), *((char*) p + 2), *((char*) p + 3), x);
	union myU {
		int x;
		char a[4];
	} y;
	y.x = 0x17654321;
	printf("%x %x %x %x = %x", y.a[0], y.a[1], y.a[2], y.a[3], y.x);
	return 0;
}