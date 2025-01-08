#define _CRT_SECURE_NO_WARNINGS 1



//2010ͳ�� ��n��n>1�������������һ��һά����R�У���R������ѭ������P��λ��

//void Init_R(int arr[N])
//{
//	for (int i = 0; i < N; i++)
//	{
//		arr[i] = i;
//	}
//}
//void Print(int arr[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//�ҵĽⷨ��
//void Reverse(int arr[N], int from, int to)
//{
//	int temp[N] = { 0 };
//	for (int i = 0; i < from; i++)
//	{
//		temp[i] = arr[i];
//	}
//	for (int i = 0; i < to; i++)
//	{
//		arr[i] = arr[from + i];
//	}
//	for (int i = 0; i < from; i++)
//	{
//		arr[to + i] = temp[i];
//	}
//
//}
//ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)

//�𰸽ⷨ ���򣺣�a^-1*b^-1��^-1=ba
//int main()
//{
//	int R[N] = { 0 };
//	Init_R(R);
//	Print_R(R);
//	int p = 0;
//	scanf("%d", &p);
//	Reverse(R, p, N - p);
//	Print_R(R);
//	return 0;
//}
//#include<stdio.h>
//#include<assert.h>
//#define N 3
//void Print(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void Combination(int arr1[N], int arr2[N],int arr3[2*N])
//{
//	int m = 0, n = 0;
//	for (int i = 0; i < 2 * N; i++)
//	{
//		if (m == N)
//		{
//			arr3[i] = arr2[n++];
//		}
//		else if (n == N)
//		{
//			arr3[i] = arr1[m++];
//		}
//		else if ( arr1[m] <= arr2[n])
//		{
//			arr3[i] = arr1[m++];
//		}
//		else 
//		{
//			arr3[i] = arr2[n++];
//		}
//		
//	}
//}
//
//
//int main()
//{
//	int A[N] = { 1,3,5 };
//	int B[N] = { 2,4,6 };
//	int C[2 * N] = { 0 };
//	Print(A,N);
//	Print(B,N);
//	Combination(A, B, C);
//	Print(C,2*N);
//	printf("%d", C[N-1]);
//	return 0;
//}
//#include<stdio.h>
//#define NUM 10
//#define false -1;
//int Majority(int arr[], int n);
//void Init_arr(int arr[], int n)
//{
//	printf("������%d��Ԫ��:>",n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
////�ҵĵͼ��汾�� ʱ�临�Ӷ�O(n^2)
//int Majorty(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int count = 0;
//		int tmpe = arr[i];
//		for (int j = i; j < n; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//			if (count > n / 2)
//			{
//				return arr[i];
//			}
//		}
//	}
//	return false;
//}

//int main()
//{
//	int arrA[NUM] = { 0 };
//	Init_arr(arrA, NUM);
//	int maxjorty = Majority(arrA, NUM);
//	if (maxjorty != -1)
//		printf("��Ԫ���ǣ�%d\n", maxjorty);
//	else
//		printf("�����鲻������Ԫ��\n");
//	
//	return 0;
//}


//���Ž� ʱ�临�Ӷ�O(n)
//������Ԫ�� M ���������ƣ��ڱ��������У���Ԫ�����ջ���������з���Ԫ�أ�������Ȼʣ�¸������Ԫ�ء����磺

//����Ԫ�� M �ͷ���Ԫ������ͬ��������ʱ�����ǻ��໥������

//��Ϊ��Ԫ�ص�����������������Ԫ�ص��ܺͣ���˼�ʹ�ڹ�����������Ԫ������Ԫ�����������Ԫ����Ȼ���Ϊ���յĺ�ѡ�ߡ�
//
//int Majority(int A[], int n)
//{
//	int i, c, count = 1;
//	c = A[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (A[i] == c)
//			count++;
//		else
//			if (count > 0)
//				count--;
//			else {
//				c = A[i];
//				count = 1;
//			}
//	}
//	if (count > 0)
//		for (i = count = 0; i < n; i++)
//			if (A[i] == c)
//				count++;
//	if (count > n / 2)
//		return c;
//	else
//		return -1;
//}

//�ҳ�δ���ֵ���С������

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#define NUM 10

void Init_Arr(int arr[], int n)  //��ֵ
{
	printf("������%d��Ԫ��:>",n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int findMissMin(int arr[], int n)
{
	int i = 0;
	int* p = (int*)malloc(sizeof(int) * n); //p������� ����ռ�
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	memset(p, 0, sizeof(int) * n);			//��ֵ 0
	for (i = 0; i < n; i++)
	{
		if (arr[i] > 0 && arr[i] <= n)		//��arr[i]λ��1~n֮�䣬�ͱ��p	������Ҳ����arr�����ݸպþ���1~n
		{
			p[arr[i] - 1] = 1;
		}
	}
	for (i = 0; i < n; i++)				//ɨ��B ����i+1
		if (p[i] == 0)
		{
			break;
		}
	free(p);						//�ͷſռ�
	p = NULL;
	return i + 1;
}


int main()
{
	int arr[NUM] = { 0 };
	Init_Arr(arr, NUM);
	int ret = findMissMin(arr, NUM);
	printf("������δ���ֵ���С�������ǣ�%d", ret);
	
	return 0;
}