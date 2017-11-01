#include<stdio.h>
char * mitob(int, char *);
void showb(char*);
int main(void)
{
	int a;
	char ch[33];
	scanf("%d", &a);
	showb(mitob(a, ch));
	return 0;
}
char * mitob(int n, char *ch)
{
	for (int i = 31; i >= 0; i--, n >>= 1)
		ch[i] = (1 & n) + '0';
	ch[32] = '\0';
	return ch;
}
void showb(char* ch)
{
	for (int i = 0; ch[i]; i++)
	{
		putchar(ch[i]);
		if ((i + 1) % 4 == 0)
			putchar(' ');
	}
}
/*
void showb(char* ch)
{
	int i = 0;
	while (ch[i])
	{
		putchar(ch[i]);
		if (!(++i % 4) && ch[i])
			putchar(' ');
	}
}*/