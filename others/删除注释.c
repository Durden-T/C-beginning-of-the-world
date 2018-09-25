#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	char ch,a;
	bool instr = false;
	while ((ch = getchar())!='`')
	{
		if (ch=='\''||ch=='"')
		{
			if (instr)
				instr = false;
			else instr = true;
			putchar(ch);
		}
		else if (!instr&&ch=='/')
		{
			if ((a = getchar())=='/')
				while ((a=getchar())!='\n'&&a!='`');
			else
			{
				if (a=='*')
					while (getchar()!='*'||(getchar()=='*'&&getchar()!='/'));
				else
					printf("%c%c", ch, a);
			}
		}
		else
			putchar(ch);
	}
	return 0;
}