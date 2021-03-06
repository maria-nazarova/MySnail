#include<stdio.h>

int bitAnd(int n, int m){
	return (~((~n)|(~m)));
}

int bitXor (int n, int m){
	return(~(~(m&~n)&~(n&~m)));
}

int thirdBits (void){
	return 36 + (73 << 8) + (146 << 16) + (36 << 24);
}

int fitsBits (int x, int n){
	int m = (1 << (n - 1))+ ~0;
	int negm = ~m;
	return !((x & m) ^ x) | !(negm & x ^ negm);
}

int sign(int x){
	int t = 1 << 31;
	return  !(t & x) + !(t & x) + ~!x;
}

int getByte(int x, int n) {
	int m = 255 << (n << 3);
	return ((m & x) >> (n << 3)) & 255;
}

int logicalShift (int x, int n){
	int m = ~(1 << 31);
	m = m >> (n);
	m = (m << 1) + 1;
	x = x >> n;
	x = x & m;
	return x;
}

int addOK(int x, int y) {
	int c = x + y, m = 1 << 31;
	x = x & m;
	y = y & m;
	c = c & m;
	return !!(((!c) | x | y) & (c | (!x) | (!y)));
}

int bang(int x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return (~x) & 1;
}

int conditional(int x, int y, int z){
	x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
	x =  ((x & 1) + ~0);
	return ((~x) & y) + (x & z);
}

int isPower2(int x){
	int a = x, b = x;
	a |= (a << 1);
    a |= (a << 2);
    a |= (a << 4);
    a |= (a << 8);
    a |= (a << 16);
	b = ((~a) << 1) + 1;
	return !(a & b + ~x + 1) + ~!(x ^ (1 << 31)) + 2 + ~!x;
}
