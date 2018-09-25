#include<stdio.h>//cpp p372 12
#include<ctype.h>
int main(void)
{
	char ch;
	int num = 0, big = 0, sma = 0, bd = 0, dc = 0;
	int flag = 0;
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch) && !flag)
		{
			flag = 1;
			dc++;
		}
		else if (!isalpha(ch))
			flag = 0;
		if (isspace(ch))
			continue;
		if (isdigit(ch))
			num++;
		if (ispunct(ch))
			bd++;
		if (isupper(ch))
				big++;
		if (islower(ch))
				sma++;		
	}
	printf("\nnum=%d\nupper=%d\nlower=%d\npunct=%d\nwords=%d\n", num, big, sma, bd, dc);
	getchar();
	getchar();
	return 0;
}