#include<stdio.h>
int main(void)
{
	int x, n, a[5], ans[5];
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int t = 0, m = 0, temp = 0; t < n; t++)
	{
		for (int i = 0; i < n; i++)
			if (m < x%a[i])
			{
				temp = i;
				m = x%a[temp];
				ans[t] = i + 1;
			}
		a[temp] = 1;
		x = m;
		temp = 0;
		m = 0;
	}
	printf("%d\n", x);
	for (int i = 0; i < n; i++)
		if (i < n - 1)
			printf("%d ", ans[i]);
		else printf("%d", ans[i]);
		return 0;
}