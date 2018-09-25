#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char a[11];
	int i = 0, flag = 0;
	while ((a[i++] = getchar())!='\n'&&a[i-1]!=' '&&a[i-1]!=EOF&&isdigit(a[i-1]));
	i--;
	if (i%3==1)
		flag = 1;
	else if (i%3==2)
		flag = 2;
	for (int c = 0, count = 0; c<i; c++, count++)
	{
		if (flag && c==flag)
		{
			putchar(',');
			flag = 0;
			count = 0;
		}
		if (count&& c!=i-1&&count%3==0)
			putchar(',');
		putchar(a[c]);
	}
	return 0;
}