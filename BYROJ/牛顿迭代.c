#include<stdio.h>
int main(void)
{
	int n;
	double ans=0.5;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		ans = ans + 1 + 1 / ans;
	printf("%lf", ans);
	return 0;
}