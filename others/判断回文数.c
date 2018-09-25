#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
	int a;
	char b[100], c[100];
	scanf("%d", &a);
	_itoa(a, b, 10);
	for (int i = 0; i < strlen(b); i++)
		c[i] = b[strlen(b) - i - 1];
	printf("%d", !(strncmp(b, c, strlen(b))));
	return 0;
}