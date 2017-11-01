#include<stdio.h>
int GetMonthDays(int year, int month)
{
    int leap = year % 100 ? !(year % 4) : !(year % 400);
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2 && leap)
        return 29;
    else if (month == 2 && !leap)
        return 28;
    else return 31;
}
int GetWeekDay(int year, int month, int day)
{
    int monthdays = 0;
    for (int i = 1; i <= month - 1; i++)
        monthdays += GetMonthDays(year, i);
    int days = ((year - 1) / 400 + (year - 1) / 4 - (year - 1) / 100)) + 365*year-364 + monthdays;
    return days % 7;
}
void PrintMonthCalender(int startDay, int days)
{
    for (int w = 0; w < startDay; w++)
        printf("\t");
    for (int i = 1; i <= days; i++)
    {
        printf("%d\t", i);
        if (i == 7 - startDay || i == 14 - startDay || i == 21 - startDay || i == 28 - startDay)
            printf("\n");
    }
}
main()
{
    int year, month;
    printf("Please input year and month:");
    scanf("%d%d", &year, &month);
    printf("The result is:\n\t\t\t%d-%d\nSun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n", year, month);
    PrintMonthCalender(GetWeekDay(year, month), GetMonthDays(year, month));
}