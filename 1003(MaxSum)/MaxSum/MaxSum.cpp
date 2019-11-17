#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int T;
	int arr[1000];
	int n, count = 1;
	scanf("%d", &T);
	while (count <= T) {
		//数据输入
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

		//动态规划找最大子串
		int MaxSum = arr[0], CurrentSum = arr[0];
		//初始化最大子串位置
		int MaxSumBeginPos = 1, MaxSumEndPos = 1;
		//初始化当前子串位置
		int CurrentBeginPos = 1, CurrentEndPos = 1;
		for (int i = 1; i < n; ++i) {
			//如果当前和 < 0, 更新当前和的起始和结束位置
			if (CurrentSum < 0) {
			CurrentSum = arr[i];
			CurrentBeginPos = i + 1;
			CurrentEndPos = i + 1;
			}
			//更新当前和，当前和结束位置
			else{
			CurrentSum += arr[i];
			CurrentEndPos++;
			}
			//如果当前和大于之前的最大和，更新最大值起始位置
			if (CurrentSum > MaxSum) {
				MaxSum = CurrentSum;
				MaxSumBeginPos = CurrentBeginPos;
				MaxSumEndPos = CurrentEndPos;
			}
		}
		printf("Case %d:\n", count);
		printf("%d %d %d\n", MaxSum, MaxSumBeginPos, MaxSumEndPos);
		if (count < T)
			printf("\n");
		
		count++;
	}
	
	return 0;
}


