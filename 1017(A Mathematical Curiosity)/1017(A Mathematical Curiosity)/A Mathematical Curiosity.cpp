//0 < a < b < n and (a^2+b^2 +m)/(ab) is an integer.


#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	int N, n, m;
	scanf("%d", &N);
	while (N--) {
		int T = 1;
		while (scanf("%d%d", &n, &m)) {
			if (n == 0 && m == 0)
				break;
			int count = 0;
			for (int a = 1; a < n; ++a) {
				for (int b = a + 1; b < n; ++b) {
					double tmp = (double)((a * a) + (b * b) + m) / (double)(a * b);
					if (tmp == (int)tmp)
						count++;
				}
			}
			printf("Case %d: %d\n", T, count);
			T++;
		}
		if(N != 0)
			printf("\n");
	}
	
	return 0;
}