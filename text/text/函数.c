#include<stdio.h>
#include<string.h>
char * mgets(char *s, int i)
{
	char *r, *f;
	r = fgets(s, i, stdin);
	if (r)
	{
		f = strchr(s, '\n');
		if (f)
			*f = '\0';
		else while (getchar() != '\n');
	}
	return r;
}
int getlet(const char * s)
{
	char c = getchar();
	while (strchr(s, c) == NULL)
	{
		printf("Enter a character in the list %s\n", s);
		while (getchar() != '\n');
		c = getchar();
	}
	while (getchar() != '\n');
	return c;
}