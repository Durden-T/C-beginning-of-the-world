#include<stdio.h>
int main(void)
{
	int t,tmp,sum,min;
	scanf("%d", &t);
	getchar();
	int spend[26] = { 0 };
	for (int i = 1, j = 25; i!=j; i++, j--)
		spend[i] = spend[j] = i;
	spend[13] = 13;
	for (int index = 0; index<t; index++)
	{
		min = 99999;
		int letter[26] = { 0 };
		while ((tmp = getchar())!='\n')
			letter[tmp-'a']++;
		for (int i = 0; i<26; i++)
		{
			sum = 0;
			for (int j = 0; j<26; j++)
				if (letter[j])
					if (i>j)
						sum += letter[j]*spend[i-j];
					else
						sum += letter[j]*spend[j-i];
			if (sum<min)
				min = sum;
		}
		printf("%d\n", min);
	}
	return 0;
}