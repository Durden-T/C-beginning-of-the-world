#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main(void)
{
	int *a=(int*)malloc(9999*sizeof(int));
	int n;
	scanf("%d", &n);//n代表数组中有几个数字
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);//(数组，需要排序的数字个数，单个数字所占内存大小，比较函数）
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}









#include<stdio.h>//从大到小排序 p318 6
void list(int *ptr,int n);
int main(void)
{
	int a[5] = { 5,7,6,1,9 };
	list(a,5);
	printf("%d    %d    %d    %d    %d    ",a[0], a[1], a[2], a[3], a[4]);
	getchar();
	getchar();
	return 0;
}
void list(int *ptr,int n)
{
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; a + b < n; b++)
		{
			if (*(ptr + a) < *(ptr + a + b))
			{
				int temp = 0;
				temp = *(ptr + a);
				*(ptr + a) = *(ptr + a + b);
				*(ptr + a + b) = temp;
			}
		}
	}
}