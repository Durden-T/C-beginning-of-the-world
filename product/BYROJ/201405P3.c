#include<stdio.h>
int isPrime(int n)
{
		double l = sqrt(n);
		for (int i = 2; i <= l; i++)
			if (!(n % i))
				return 0;
		return 1;
}
int printFactor(int n)
{
	int flag = 0;
	for (int i = 2; i <= n; i++)
		if (n % i == 0 && isPrime(i))
		{
			if (flag)
				printf("*%d", i);
			else
			{
				printf("%d", i);
				flag = 1;
			}
			n /= i;
			i = 1;
		}
}
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("The result is:");
	for (int i = a; i <= b; i++)
	{
		printf("\n%d=", i);
		if (isPrime(i))
			printf("%d", i);
		else printFactor(i);	
	}
	return 0;
}