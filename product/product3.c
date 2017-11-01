#include <stdio.h>//cpp p276 8
double power(double n, int p);
int main(void)
{
	double x, xpow;
	int exp;
	printf("Enter a number and the integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip -- bye!\n");
	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	int i,temp;
	if (n != 0)
	{
		if (p != 0)
		{
			temp = p;
			p = abs(p);
			for (i = 1; i <= p; i++)
				pow *= n;
			if (temp < 0)
				pow = 1 / pow;
		}
		else
			pow = 1;
	}
	else
	pow = 0;
	return pow;
}

double power(double n, int p)
{
	double pow = 1;
	int i = 1;
	int temp;
	if (n != 0)
	{
		if (p != 0)
		{
			temp = p;
			p = abs(p);
			n*=n;
			pow = power(n, p);

			if (temp < 0)
				pow = 1 / pow;
		}
		else
			pow = 1;
	}
	else
		pow = 0;
	return pow;
}
