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
	scanf("%d", &n);//n�����������м�������
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);//(���飬��Ҫ��������ָ���������������ռ�ڴ��С���ȽϺ�����
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}









#include<stdio.h>//�Ӵ�С���� p318 6
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