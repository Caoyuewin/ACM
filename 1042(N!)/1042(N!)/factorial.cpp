#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	//����׳˵�ÿһλ����һλ��ʼ��Ϊ1
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int num[100000] = { 1 };
		int end = 0;
		int carry = 0;
		for (int i = 1; i <= N; ++i) {
			carry = 0;
			//ģ��˷�
			for (int j = end; j >= 1; --j) {
				int tmp = num[j] * i + carry;
				num[j] = tmp % 10;
 				carry = tmp / 10;
			}
			num[0] = num[0] * i + carry;

			//����Ԫ�أ������λ
			while (num[0] >= 10) {
				//�������һλ
				for (int j = end; j >= 1; --j) {
					num[j + 1] = num[j];
				}
				num[1] = num[0] % 10;
				num[0] /= 10;
				end++;//λ��+1
			}
		}
		for (int i = 0; i <= end; ++i) {
			printf("%d", num[i]);
		}
		printf("\n");
	}

	return 0;
}


//int main() {
//	//����׳˵�ÿһλ����һλ��ʼ��Ϊ1
//	int num[10000] = { 1 };
//	int N;
//	while (scanf("%d", &N) != EOF)
//	{
//		int end = Calculate(N, num);
//		for (int i = 0; i <= end; ++i) {
//			printf("%d", num[i]);
//		}
//	}
//	
//	return 0;
//}
//
//int Calculate(int n, int num[]) {
//	int end = 0;//��¼���һλ��λ��
//	int carry = 0;
//	for (int i = 1; i < n; ++i) {
//		//ģ��˷�
//		for (int j = end; j >= 0; --j) {
//			int tmp = num[j] * i + carry;
//			num[j] = tmp % 10;
//			carry = tmp / 10;
//		}
//
//		//����Ԫ�أ������λ
//		while (num[0] >= 10) {
//			//�������һλ
//			for (int j = end; j >= 1; --j) {
//				num[j + 1] = num[j];
//			}
//			num[1] = num[0] % 10;
//			num[0] /= 10;
//			end++;//λ��+1
//		}
//	}
//	return end;
//}
