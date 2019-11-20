#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//�ж��Ƿ���Ҫ������һ��
bool Judge(int arr[], int size) {
	for (int i = 1; i < size; ++i) {
		if (arr[i] != arr[i - 1])
			return true;
	}
	return false;
}

int main() {
	//ѧ������
	int N;
	int stu_count[1024];
	while (scanf("%d", &N)) {
		//��������
		if (N == 0)
			break;
		//����
		for (int i = 0; i < N; ++i) {
			scanf("%d", &stu_count[i]);
		}

		int whistle_count = 0;
		while (Judge(stu_count, N)) {
			int i;
			int k = stu_count[N - 1] / 2;//k����ֳ�����һ��
			for (i = 0; i < N; ++i) {
				int tmp = stu_count[i] / 2 + k;
				k = stu_count[i] / 2;
				stu_count[i] = tmp;
				if (stu_count[i] % 2 != 0)
					stu_count[i]++;
			}

			whistle_count++;
		}
		printf("%d %d\n", whistle_count, stu_count[0]);
	}
	return 0;
}