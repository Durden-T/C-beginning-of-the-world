//TCPL 121 5-14...
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5000
#define NUMERIC 1
#define DECR 2
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void msort(void *lineptr[], int begin, int end, int(*cmp)(void *, void *));
int numcmp(char *, char *);
int option = 0;
int main(int argc,char* argv[])
{
	int nlines;
	char *lineptr[MAX];
	while (--argc&&*argv[argc]=='-')
		switch (argv[argc][1])
		{
		case 'n':
			option |= NUMERIC;
			break;
		case 'r':
			option |= DECR;
			break;
		default:
			printf("sort:illegal option %c\n", argv[argc][1]);
			argc = 0;
		}
	if (argc<0)
	{
		puts("Usage:-n -r");
		return 1;
	}
	if ((nlines = readlines(lineptr, MAX))>=0)
	{
		msort((void **)lineptr, 0, nlines-1,(int (*)(void*,void*))(option&NUMERIC?numcmp:strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort.\n");
		return 2;
	}
}
int readlines(char *lineptr[], int nlines)
{
	static char temp[MAX][MAX];
	int i = 0;
	while (i<nlines&&(lineptr[i] = gets_s(temp[i], MAX-1))&&*temp[i])
		i++;
	return i<nlines ? i : -1;
}
void writelines(char *lineptr[], int nlines)
{
	if (option&DECR)
		while (nlines--)
			puts(lineptr[nlines]);
	else
		while (nlines--)
			puts(*lineptr++);
}
void msort(void *lineptr[], int begin, int end, int(*cmp)(void *, void *))
{
	if (begin>=end)
		return;
	int i = begin, j = end;
	void *key = lineptr[i];
		while (i<j)
		{
			while (i<j && cmp(lineptr[j], key)>=0)					
				j--;
			if (i<j)
				lineptr[i++] = lineptr[j];
			while (i<j && cmp(lineptr[i], key)<=0)
				i++;
			if (i<j)
				lineptr[j--] = lineptr[i];
		lineptr[i] = key;
		msort(lineptr, begin, i-1, cmp);
		msort(lineptr, i+1, end, cmp);
	}
}
int numcmp(char *s1, char *s2)
{
	double a = atof(s1), b = atof(s2);
	if (a<b)
		return -1;
	if (a>b)
		return 1;
		return 0;
}