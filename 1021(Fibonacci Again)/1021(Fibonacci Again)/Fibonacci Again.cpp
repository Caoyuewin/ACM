#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

//int main() {
//	int *f = (int*)malloc(sizeof(int) * 1000000);
//	f[0] = 7, f[1] = 11;
//	for (int i = 2; i < 1000000; ++i) {
//		f[i] = f[i - 1] + f[i - 2];
//	}
//	int n;
//	while (scanf("%d", &n) != EOF) {
//		int fib = f[n];
//		if (fib % 3 == 0)
//			printf("yes\n");
//		else
//			printf("no\n");
//	}
//	return 0;
//}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n % 4 == 2)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}