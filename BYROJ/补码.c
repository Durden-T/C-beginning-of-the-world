#include<stdio.h>
int main(void)
{
	int a,m;
	long b,n;
	char _a[33],_b[65];
	scanf("%d%ld", &a, &b);
	m = a;
	n = b;
	if (a < 0)
		a = ~(-a) + 1;
	if (b < 0)
		b = ~(-b) + 1;
	for (int i = 31; i >= 0; i--, a >>= 1)
		_a[i] = (1 & a) + '0';
	_a[32] = '\0';
	for (int i = 63; i >= 0; i--, b >>= 1)
		_b[i] = (1 & b) + '0';
	_b[64] = '\0';
	printf("The binary form of int %d is: %s\n", m, _a);
	printf("The binary form of long %ld is: %s\n", n, _b);
	return 0;
}