#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int partition(int arr[], int left, int right) {
	int key = arr[left];
	while (left < right) {
		while (arr[right] >= key && left < right)
			--right;
		if (left >= right)
			break;
		else
			arr[left] = arr[right];

		while (arr[left] <= key && left < right)
			++left;
		if (left >= right)
			break;
		else
			arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}

void QuickSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = partition(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid + 1, right);
	}
	return;
}

int main() {
	int T, N, arr[1024]; 
	scanf("%d", &T);
	while (T) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
		}
		QuickSort(arr, 0, N-1);
		for (int i = 0; i < N; ++i) {
			if(i == N - 1)
				printf("%d\n", arr[i]);
			else
				printf("%d ", arr[i]);
		}
		
		T--;
	}
	return 0;
}