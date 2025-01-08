#define _CRT_SECURE_NO_WARNINGS 1



//2010统考 将n（n>1）个整数存放在一个一维数组R中，将R的序列循环左移P个位置

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
//我的解法：
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
//时间复杂度：O(n) 空间复杂度：O(1)

//答案解法 逆序：（a^-1*b^-1）^-1=ba
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
//	printf("请输入%d个元素:>",n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
////我的低级版本： 时间复杂度O(n^2)
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
//		printf("主元素是：%d\n", maxjorty);
//	else
//		printf("该数组不存在主元素\n");
//	
//	return 0;
//}


//最优解 时间复杂度O(n)
//由于主元素 M 的数量优势，在遍历过程中，主元素最终会抵消掉所有非主元素，并且仍然剩下更多的主元素。例如：

//当主元素 M 和非主元素以相同数量出现时，它们会相互抵消。

//因为主元素的数量多于其他所有元素的总和，因此即使在过程中有其他元素与主元素相抵消，主元素仍然会成为最终的候选者。
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

//找出未出现的最小正整数

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#define NUM 10

void Init_Arr(int arr[], int n)  //赋值
{
	printf("请输入%d个元素:>",n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int findMissMin(int arr[], int n)
{
	int i = 0;
	int* p = (int*)malloc(sizeof(int) * n); //p标记数组 分配空间
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	memset(p, 0, sizeof(int) * n);			//赋值 0
	for (i = 0; i < n; i++)
	{
		if (arr[i] > 0 && arr[i] <= n)		//若arr[i]位于1~n之间，就标记p	最坏的情况也就是arr里数据刚好就是1~n
		{
			p[arr[i] - 1] = 1;
		}
	}
	for (i = 0; i < n; i++)				//扫描B 返回i+1
		if (p[i] == 0)
		{
			break;
		}
	free(p);						//释放空间
	p = NULL;
	return i + 1;
}


int main()
{
	int arr[NUM] = { 0 };
	Init_Arr(arr, NUM);
	int ret = findMissMin(arr, NUM);
	printf("该数组未出现的最小正整数是：%d", ret);
	
	return 0;
}