#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t maxLen = 25;

int main(){
	char str[maxLen];
	scanf("%s", str);
	int n = 0, len = strlen(str), i = 0;
	_Bool f = 0, d = 0;
	if (str[0] == '-') f = 1;
	else 
		if (str[0] >= '0' && str[0] <= '9') n = str[0] - '0';
		else { 
			printf("Starts with a non-numeric symbol"); 
			d = 1;
		}
	if (!d) {
		for (i = 1; i < len; ++i) {
			if (str[i] >= '0' && str[i] <= '9') n = n * 10 + str[i] - '0';
			else {
				d = 1;
				break;
			}
		
		}
	}
	if (f) n = -n;
	if (d) printf("Couldn't convert the whole string, %d numeric symbols in the beginning of the string out of %d\n", i, len);
		else printf("Converted the whole string\n");
	if (f && n > 0 || !f && n < 0) printf("Value too big for an int size");
		else printf("n = %d", n);
}