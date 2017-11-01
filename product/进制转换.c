//±±” OJ
#include<stdio.h>
char * mitob(int, char);
int main(void)
{
	int sourse;
	char choice;
	scanf("%d %c", &sourse, &choice);
	printf("%s", mitob(sourse, choice));
	return 0;
}
char * mitob(int a, char b)
{
	static char ch[33];
	int i = 1;
	int x = 0;
	int t;
	int jud;
	if (a < 0)
	{
		a = -a;
		ch[0] = '-';
		x = 1;
	}
	switch (b)
	{
	case 'B':	t = 2;	break;
	case 'O':	t = 8;	break;
	default:	t = 16;
	}
	if (t != 16)
		for (; i; i /= t, x++)
		{
			ch[x] = a % b + '0';
			a /= t;
		}
	else
		for (; i; i /= t, x++)
		{
			jud = a % b ;
			if (jud < 10)
				ch[x] = jud + '0';
			else
				ch[x] = 'A' + jud - 10;
			a /= t;
		}
	ch[x] = '\0';
	return ch;
}



	/*for (; a / i; i *= t);
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
	return ch;
}*/