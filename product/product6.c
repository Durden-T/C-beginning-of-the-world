#include<stdio.h>
#include<stdlib.h>
#include<string.h>//cpp p411 9
int main(void)
{
	printf("How many words do you wish to enter?");
	int r;
	scanf("%d", &r);
	printf("Enter %d words now:\n", r);
	char **ptr = malloc(r * sizeof(char*));
	getchar();
	for (int i = 0; i < r; i++)
	{
		char ch[12];
		scanf("%s", ch);
		ptr[i] =(char*)malloc(strlen(ch) + 1);
		strcpy(ptr[i], ch);
	}
		printf("Here are your words:\n");
		for (int i = 0; i < r; i++)
			printf("%s\n", ptr[i]);	
		return 0;
}


