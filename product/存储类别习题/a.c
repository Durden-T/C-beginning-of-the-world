#include"БъЭЗ.h"
static int temp;
static double _0, _1;
void set_mode(int mode)
{
	static int pre = 0;
	if (mode == 0 || mode == 1)
		pre = mode;
	else
	{
		mode = pre;
		printf("Invalid mode specified.Mode %d used.", mode);
	}
	temp = mode;
}
void get_info(void)
{
	if (temp == 0)
	{
		printf("Enter distance traveled in kilometers:");
		static double km;
		scanf("%lf", &km);
		printf("Enter fuel consumed in liters:");
		static double yh;
		scanf("%lf", &yh);
		_0 = yh / (km/100);
	}
	else
	{
		printf("Enter distance traveled in miles:");
		static double miles;
		scanf("%lf", &miles);
		printf("Enter fuel consumed in gallons:");
		static double gallons;
		scanf("%lf", &gallons);
		_1 = miles /gallons;
	}
}
void show_info(void)
{
	if(temp==0)
	printf("Fuel consumption is %lf ltiers per 100 km.", _0);
	else
		printf("Fuel consumption is %lf miles per gallon.", _1);
}