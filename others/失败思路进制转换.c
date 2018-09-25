#include<stdio.h>
char *mitob(int, char*, int);
int main(void)
{
	int sourse;
	char choice,ans[33];
	scanf("%d%c", &sourse,&choice);
	printf("%s",mitob(sourse,ans,choice));
	return 0;
}
char * mitob(int a, char *ch,int b)
{
	char temp[12];
	int t;
		switch(b)
		{
		case 'B':	t = 2;	break;
		case 'O':	t = 8;	break;
		case 'H':	t = 16; 
		}
	for (int i = 31; i >= 0; i--, a >>= 1)
		ch[i] = (1 & a) + '0';
	switch (b)
	{
	case 'B':	ch[32] = '\0';		break;
	case 'O':
		for (int i = 10, c = 31; i >= 0; i--, c-=3)
			temp[i] = ch[c] + 2*ch[c - 1] + 4*ch[c - 2] - 6 * '0';
	case 'H':	t = 16;
	}
	ch[32] = '\0';
	return ch;
}