#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t maxSize = 300;

void to_base_64(char *str, char *base_64) {
	int len = strlen(str);
	for (int i = 0; i < len; i += 3) {
		int c = (str[i] << 16) + (str[i + 1] << 8) + str[i + 2];
		char a[4] = {c >> 18, (c >> 12) % (1 << 6), (c >> 6) % (1 << 6), c % (1 << 6)};
		for (int j = 0; j < 4; j++) {
			int t = a[j];
			if (t < 26) {
				base_64[i / 3* 4 + j] = 'A' + t;
			} else if (t < 52) {
				base_64[i / 3 * 4 + j] = 'a' + t - 26;
			} else if (t < 62) {
				base_64[i / 3 * 4 + j] = t + '0' - 52;
			} else if (t == 62) {
				base_64[i / 3 * 4 + j] = '+';
			} else {
				base_64[i / 3 * 4 + j] = '/';
			}
		}
	}
	if (len % 3 == 1) {
		base_64[(len - 1) / 3 * 4 + 2] = '=';
		base_64[(len - 1) / 3 * 4 + 3] = '=';
	}
	if (len % 3 == 2) {
		base_64[(len - 1) / 3 * 4 + 3] = '=';
	}
}

void from_base_64(char *base_64, char *out) {
	int len = strlen(base_64);
	int p = 0;
		if (base_64[len - 1] == '=') {
			p = 1;
		}
	if (base_64[len - 2] == '=') {
		p = 2;
	}
	for (int i = 0; i < len; i += 4) {
		for (int j = 0; j < 4; ++j) {
			if (base_64[i + j] >= 'A' && base_64[i + j] <= 'Z') {
				base_64[i + j] -= 'A';
			} else if (base_64[i + j] >= 'a' && base_64[i + j] <= 'z') {
				base_64[i + j] = base_64[i+j] - 'a' + 26;
			} else if (base_64[i + j] >= '0' && base_64[i + j] <= '9') {
				base_64[i + j] = base_64[i+j] - '0'  + 52;
			} else if (base_64[i + j] == '+') {
				base_64[i + j] = 62;
			} else {
				base_64[i + j] = 63;
			}
		}
		int c = (base_64[i] << 18) + (base_64[i + 1] << 12) + (base_64[i + 2] << 6) + base_64[i + 3];
		out[i / 4 * 3] = c >> 16;
		out[i / 4 * 3 + 1] = (c >> 8) % (1 << 8);
		out[i / 4 * 3 + 2] = c % (1 << 8);
	}
	if (p) {
		out[len / 4 * 3 - 1] = 0;
	}
	if (p == 2) {
		out[len / 4 * 3 - 2] = 0;
	}
}

int main() {
	char str[maxSize], base_64[maxSize / 3 * 4], out[maxSize];
	memset(base_64, 0, maxSize * sizeof(char) / 3 * 4);
	memset(out, 0, maxSize * sizeof(char));
	scanf("%s", str);
	to_base_64(str, base_64);
	printf("%s \n\n", base_64);
	
	from_base_64(base_64, out);
	printf("%s", out);
}