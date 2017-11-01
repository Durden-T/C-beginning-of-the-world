#include<stdio.h>
#include"БъЭЗ.h"
int main(void)
{
	int mode;
	printf("Enter 0 for metric mode,1 for US mode:");
	int pre = -1;
	while (scanf("%d",&mode) &&mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("\nEnter 0 for metric mode,1 for US mode(-1 to quit):");
	}
	printf("Done.\n");
	return 0;
}