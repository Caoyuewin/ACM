#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7
int main() {
	int A, B, n;
	int tmp[10000];
	while (1) {
		//输入数据
		scanf("%d%d%d", &A, &B, &n);
		//停止输入
		if (A == 0 && B == 0 && n == 0)
			break;
		//n = n % 7
		tmp[1] = tmp[2] = 1;
		/*int f3 = (A * 1 + B * 1) % 7;*/
		int i;
		for (i = 3; i < 10000; ++i) {
			tmp[i] = (A * tmp[i - 1] + B * tmp[i - 2]) % 7;
			if (tmp[i] == 1 && tmp[i - 1] == 1)
				break;
		}
		n = n % (i - 2);
		tmp[0] = tmp[i - 2];
		printf("%d\n", tmp[n]);
	}
	return 0;
}