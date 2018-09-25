#include<stdio.h>
int main(void)
{
	int a;
	char b;
	char ch[33];
	scanf("%d %c", &a, &b);
	if (a < 0)
	{
		a = -a;
		putchar('-');
	}
	int i = 1;
	int x = 0;
	int t;
	int jud;
	switch (b)
	{
	case 'B':   t = 2;  break;
	case 'O':   t = 8;  break;
	default:    t = 16;
	}
	for (; a / i; i *= t);
	i /= t;
	if (t != 16)
		for (; i; i /= t, x++)
		{
			ch[x] = (a / i) + '0';
			a %= i;
		}
	else
		for (; i; i /= t, x++)
		{
			jud = a / i;
			if (jud < 10)
				ch[x] = jud + '0';
			else
				ch[x] = 'A' + jud - 10;
			a %= i;
		}
	ch[x] = '\0';
	printf("%s", ch);
	return 0;
}