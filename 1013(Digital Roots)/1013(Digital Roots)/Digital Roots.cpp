#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Getroot(unsigned long long num) {
	int root = 0;
	while (num / 10 != 0) {
		unsigned long long tmp = num;
		root = 0;
		while (tmp) {
			root += tmp % 10;
			tmp /= 10;
		}
		num = root;
	}
	return root;
}

int main() {
	unsigned long long num;
	while (scanf("%I64u", &num)) {
		if (num == 0)
			break;
		int root = 0;
		root = Getroot(num);
		printf("%d\n", root);
	}
	return 0;
}