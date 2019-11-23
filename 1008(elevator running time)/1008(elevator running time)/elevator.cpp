#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	int N, list[1000];
	while (scanf("%d", &N)) {
		if (N == 0)
			break;
		// ‰»Î
		list[0] = 0;
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &list[i]);
		}

		int time = 0;
		for (int i = 1; i <= N; ++i) {
			if (list[i] >= list[i - 1]) {
				time += (6 * (list[i] - list[i - 1]));
			}
			else {
				time += (4 * (list[i - 1] - list[i]));
			}
			time += 5;
		}
		printf("%d\n", time);
	}
	return 0;
}