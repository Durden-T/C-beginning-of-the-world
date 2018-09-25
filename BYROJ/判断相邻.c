#include<stdio.h>
#include<string.h>
int main(void)
{
	char a,b,c;
	scanf("%c%c%c", &a, &b, &c);
	if (isalpha(b) && c - b == 1 && b - a == 1)
		printf("The letters are adjacent with each other.");
	else printf("The letters are not adjacent with each other.");
	return 0;
}