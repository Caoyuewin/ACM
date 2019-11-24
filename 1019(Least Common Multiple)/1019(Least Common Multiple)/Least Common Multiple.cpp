//��ȡһ�����ϵ���С���������������������ң�������������lcm��ľ�����С������

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int GetLCM(int x, int y) {
	if (x < y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	int bignum = x;
	while (x % y != 0) {
		x += bignum;
	}
	return x;
}

int main() {
	int m, N, num[1000];
	scanf("%d", &m);
	while (m) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num[i]);
		}
		
		/*******************************/
		int lcm = num[0];
		for (int i = 1; i < N; ++i) {
			lcm = GetLCM(lcm, num[i]);
		}
		printf("%d\n", lcm);
		m--;
	}
	return 0;
}