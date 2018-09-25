#include<stdio.h>
int main(void)
{
	int a, i;
	scanf("%d", &a);
	while (a)
	{
		int n = 0;
		while ((i = pow(2, n++)) && i <= a);
		printf("%d,", i / 2);
		a -= i / 2;
	}
	printf("\b");
	return 0;
}