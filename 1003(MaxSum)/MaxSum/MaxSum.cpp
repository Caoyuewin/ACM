#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	int T;
	int arr[1000];
	int n, count = 1;
	scanf("%d", &T);
	while (count <= T) {
		//��������
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

		//��̬�滮������Ӵ�
		int MaxSum = arr[0], CurrentSum = arr[0];
		//��ʼ������Ӵ�λ��
		int MaxSumBeginPos = 1, MaxSumEndPos = 1;
		//��ʼ����ǰ�Ӵ�λ��
		int CurrentBeginPos = 1, CurrentEndPos = 1;
		for (int i = 1; i < n; ++i) {
			//�����ǰ�� < 0, ���µ�ǰ�͵���ʼ�ͽ���λ��
			if (CurrentSum < 0) {
			CurrentSum = arr[i];
			CurrentBeginPos = i + 1;
			CurrentEndPos = i + 1;
			}
			//���µ�ǰ�ͣ���ǰ�ͽ���λ��
			else{
			CurrentSum += arr[i];
			CurrentEndPos++;
			}
			//�����ǰ�ʹ���֮ǰ�����ͣ��������ֵ��ʼλ��
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


