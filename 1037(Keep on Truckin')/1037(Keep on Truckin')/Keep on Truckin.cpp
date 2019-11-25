#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Min(int x, int y) {
	return x > y ? y : x;
}
int main() {
	int h[3];
	while (scanf("%d%d%d", &h[0], &h[1], &h[2]) != EOF) {
		int m = Min(h[0], h[1]);
		m = Min(m, h[2]);
		if (m > 168)
			puts("NO CRASH\n");
		else {
			printf("CRASH %d\n", m);
		}
	}
	return 0;
}