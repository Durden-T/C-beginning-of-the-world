//Polish Calculator TCPL p79 with Polish Calculator.c
#include<stdio.h>
#define MAX 100
int i = 0;
double compute[MAX];
void push(double f)
{
	if (i<MAX)
		compute[i++] = f;
	else
		printf("error:stack full,can't push %g\n", f);
}
double pop(void)
{
	if (i)
		return compute[--i];
	else
		printf("error:stack empty\n");
		return 0.0;
}
void clear(void)
{
	i = 0;
}
void ungets(void)
{
	compute[i] = '\0';
	puts(compute);
}