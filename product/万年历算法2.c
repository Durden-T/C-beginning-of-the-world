#include<stdio.h>
int M(int o, int u)
{
	int q = o % 100 ? !(o % 4) : !(o % 400);
	if (u == 4 || u == 6 || u == 9 || u == 11)
		return 30;
	else if (u == 2 && q)
		return 29;
	else if (u == 2 && !q)
		return 28;
	else return 31;
}
int W(int o, int u)
{
	int e = 0;
	for (int i = 1; i <= u - 1; i++)
		e += M(o, i);
	int t = (( (o - 1) / 400 + (o - 1) / 4 - (o - 1) / 100))+365*o -364 + e;
	return t % 7;
}
void y(int r, int t)
{
	for (int w = 0; w < r; w++)
		printf("\t");
	for (int i = 1; i <= t; i++)
	{
		printf("%d\t", i);
		if (i == 7 - r || i == 14 - r || i == 21 - r || i == 28 - r)
			printf("\n");
	}
}
main()
{
	int o, u;
	printf("Please input year and month:");
	scanf("%d%d", &o, &u);
	printf("The result is:\n\t\t\t%d-%d\nSun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n", o, u);
	y(W(o, u), M(o, u));
}