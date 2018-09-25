#include<stdio.h>
int GetMonthDays(int year, int month)
{
	int monthy[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int monthn[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 100 ? !(year % 4) : !(year % 400))
		return monthy[month - 1];
	else return monthn[month - 1];
}
int GetWeekDay(int year, int month)
{
	int monthdays = 0;
	for (int i = 1; i <= month - 1; i++)
		monthdays += GetMonthDays(year, i);
	int days = ((year - 1) / 400 + (year - 1) / 4 - (year - 1) / 100)+ 365 * year - 364 + monthdays;
	return days % 7;
}
void PrintMonthCalender(int startDay, int days)
{
	switch (startDay)
	{
		case 0:break;
		case 1:printf("\t"); break;
		case 2:printf("\t\t"); break;
		case 3:printf("\t\t\t"); break;
		case 4:printf("\t\t\t\t"); break;
		case 5:printf("\t\t\t\t\t"); break;
		default :printf("\t\t\t\t\t");
	}
	for (int i = 1; i <= days; i++)
	{
		printf("%d\t", i);
		if (i == 7 - startDay || i == 14 - startDay || i == 21 - startDay || i == 28 - startDay)
			printf("\n");
	}
}
int main(void)
{
	int year, month;
	printf("Please input year and month:");
	scanf("%d%d", &year, &month);
	printf("The result is:\n\t\t\t%d-%d\nSun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n", year, month);
	PrintMonthCalender(GetWeekDay(year, month), GetMonthDays(year, month));
	return 0;
}