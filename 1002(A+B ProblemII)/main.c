#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//
//#define MaxLen 1024
//
//int main() {
//	char A[MaxLen];
//	char B[MaxLen];
//	int a[MaxLen];
//	int b[MaxLen];
//	int sum[MaxLen];
//	int T;
//	scanf("%d", &T);
//	int casenum = 1;
//
//	while (T) {
//		scanf("%s%s", A, B);
//
//		//���ַ�����������
//		for (int i = 0; A[i] != '\0'; ++i)
//			a[i] = A[i] - '0';
//		for (int i = 0; B[i] != '\0'; ++i)
//			b[i] = B[i] - '0';
//
//		int sa = strlen(A) - 1;
//		int sb = strlen(B) - 1;
//		int k = 0;
//
//		//��ӵĹ���
//		int carry = 0;//��λλ
//		int i = sa, j = sb;
//		while (i >= 0 && j >= 0) {
//			int tmp = a[i] + b[j] + carry;
//			carry = 0;//��λλ����
//			if (tmp >= 10)
//				carry = 1;
//			sum[k] = tmp % 10;
//			++k;
//			--i;
//			--j;
//		}
//		//����С�������Ѿ�������
//		//A�ǽϴ������
//		while (i >= 0) {
//			int tmp = a[i] + carry;
//			carry = 0;
//			if (tmp >= 10)
//				carry = 1;
//			sum[k] = tmp % 10;
//			++k;
//			--i;
//		}
//		//B�ǽϴ������
//		while (j >= 0) {
//			int tmp = b[j] + carry;
//			carry = 0;
//			if (tmp >= 10)
//				carry = 1;
//			sum[k] = tmp % 10;
//			++k;
//			--j;
//		}
//
//		int sumsize = 0;
//		//���carryΪ1����Ȼ��Ҫ��λ,��Ӧ�ĺ͵�λ��ҲҪ��1
//		if (carry == 1) {
//			sum[k] = 1;
//			sumsize++;
//		}
//
//		//��ӡ���
//		printf("Case %d:\n", casenum);
//		sumsize = sumsize + (sa > sb ? sa : sb);
//		printf("%s + %s = ", A, B);
//		for (i = sumsize; i >= 0; --i) {
//			printf("%d", sum[i]);
//		}
//		printf("\n");
//		--T;
//		if (T) {
//			printf("\n");//��һ��
//		}
//		++casenum;
//	}
//
//	return 0;
//}
//

#include <stdio.h>

int GetMax(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int T, N;
	scanf("%d", &T);
	int lines = 0;
	while (lines < T)
	{
		scanf("%d", &N);
		int seq[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &seq[i]);
		}

		//��ʼ����ʼλ�á�����λ�á�����
		int startpos = 0, endpos = 0, MaxSum = seq[0], PreSum = seq[0], CurSum = seq[0];
		int curstart = 0, curend = 0;
		//������Ӵ�
		for (int i = 1; i < N; ++i)
		{
			if (PreSum < 0) {
				CurSum = seq[i];
				PreSum = CurSum;
				curstart = i;
				curend = i;
			}
			else {
				CurSum = seq[i] + PreSum;
				PreSum = CurSum;
				curend = i;
			}
			if (CurSum > MaxSum) {
				MaxSum = CurSum;
				startpos = curstart;
				endpos = curend;
			}

		}

		printf("Case %d\n", lines);
		printf("%d %d %d\n", MaxSum, startpos, endpos);
		if (lines != T) {
			printf("\n");
		}
		lines++;
	}
	return 0;
}