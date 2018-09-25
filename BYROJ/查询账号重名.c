#include<stdio.h>
#include<string.h>
int main(void)
{
	char local[8][7] = { {"Alice"},{ "Bob" },{ "Lucky" },{ "Kitty" },{ "Tim" },{ "Lucy" },{ "Jim" },{ "Helena" } };
	char name[51];
	int ans[5];
	int x = -1;
	while (gets_s(name,50) && strncmp("END", name, strlen(name)))
	{
		x++;
		for (int i = 0; i < 8; i++)
			if (ans[x] = !strncmp(local[i], name, strlen(local[i])))
				break;
	}
	for (int i = 0; i <= x; i++)
	{
		if (ans[i] == 1)
			puts("NO");
		else if (ans[i] == 0)
			puts("YES");
	}
	return 0;
}