#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int factorial(int n) {
	int sum = 1;
	if (n == 0)
		return sum;
	while (n) {
		sum *= n;
		n--;
	}
	return sum;
}

int main() {
	printf("n e\n");
	printf("- -----------\n");

	printf("%d ", 0);
	printf("%d\n", 1);
	printf("%d ", 1);
	printf("%d\n", 2);
	printf("%d ", 2);
	printf("%1.1f\n", 2.5);


	double approximation = 2.5;
	for (int i = 3; i < 10; ++i) {
		printf("%d ", i);
		double n = (double)factorial(i);
		approximation += (1.0 / n);
		printf("%1.9f\n", approximation);
	}
	return 0;
}