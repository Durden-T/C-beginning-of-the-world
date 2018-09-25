#include<stdio.h>
inline int power(int a, int b)
{
	int ans = a;
	for (int i = 1; i<b; i++)
		ans *= a;
	return ans;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = power(10, N-1), max = 10*i; i<max; i++)
	{
		int temp[N+1];
		for (int i = 1; i<=N; i++)
			temp[i] = power(i, N);
		int sum=0;
		for (int x = i; x; x /= 10)
			sum += temp[x%10];
		if (sum==i)
			printf("%d\n", i);
	}
	return 0;
}
