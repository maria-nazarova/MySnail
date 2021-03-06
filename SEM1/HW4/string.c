#include <stdio.h>
#include <string.h>

size_t strlen_(char *str) {
	size_t len = 0;
	while(str[len++]);
	return len - 1;
}

void strcpy_(char *dst, char *str) {
	size_t i = 0;
	do {
		dst[i] = str[i];
	} while (str[i++]);
}

void strcat_(char *dst, char *str) {
	size_t len = strlen_(dst), i = 0;
	do {
		dst[len] = str[i];
		++len;
	} while (str[i++]);
}

int strcmp_(char *str1, char *str2) {
	size_t i = 0;
	do {
		if (str1[i] > str2[i]) {
			return 1;
		}
		if (str1[i] < str2[i]) {
			return -1;
		}
	} while (str2[i++]);
		return 0;
}

size_t maxLen = 300;

int main() {
	char str[maxLen];
	printf("Enter a string\n");
	scanf("%s", str);
	printf("strlen = %d\n", strlen_(str));
	
	char dst[maxLen];
	memset(dst, 0, maxLen * (sizeof(char)));
	strcpy_(dst, str);
	printf("Copy of your string: %s\n", dst);
	
	printf("Enter a string to be added to the first one\n");
	scanf("%s", str);
	strcat_(dst, str);
	printf("Changed string : %s\n", dst);
	
	printf("Enter a string to be compared with the changed string\n");
	scanf("%s", str);
	int ans = strcmp_(dst, str);
	if (ans > 0) {
		printf("%s > %s", dst, str);
	} else if (ans == 0){
		printf("%s == %s", dst, str);
	} else {
		printf("%s < %s", dst, str);
	}
}
