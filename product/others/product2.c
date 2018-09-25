#include<stdio.h>
void menu(void);
int getchoice(int, int);
int main(void)
{
	int res;
	menu();
	while ((res = getchoice(1, 4)) != 4)
	{
		printf("You choose %d\n", res);
		menu();
	}
	printf("Bye!\n");
	return 0;
}
void menu(void)
{
	printf("Please choose one of the following:\n");
	printf("1)copy files      2)move files\n");
	printf("3)remove files    4)quit\n");
	printf("Enter the number of your choice:");
}
int getchoice(int min, int max)
{
	int ans;
	while (!scanf("%d", &ans) || ans < 1 || ans>4)
	{
		if (ans>= 1 && ans<=4)
		{
			ans = 4;
			break;
		}
		else
		{
			printf("%d is not a valid choice,please try again.\n", ans);
			menu();
		}
	}
	return ans;
}