#include<stdlib.h>
#include<stdio.h>
int x, y, N = 100;

_Bool zero(){
	return 1 > 2;
}

void mum(int p) {
	for (int i = 0; i < p; ++i);
}

int main(){
	int a,b;
	printf("local variables %p %p \n", &a, &b);
	
	printf("global variables %p %p \n", &x, &y);
	
	printf("my functions %p %p \n", zero, mum);
	
	printf("main %p \n", main);
	
	printf("system functions %p %p \n", scanf, free);
	
	int *data = malloc(N * sizeof(int));
	if (data == NULL){
		printf ("Error while allocating memory");
	} else {
		printf("data %p", data);
	}
	free(data);
		char *dataCh = malloc(N);
	if (dataCh == NULL){
		printf ("Error while allocating memory");
	} else {
		printf("dataCh %p", dataCh);
	}
	free(dataCh);
}