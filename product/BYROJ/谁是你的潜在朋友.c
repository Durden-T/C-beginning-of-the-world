#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n, m;
    scanf("%d%d", &n,&m);
    int pep[5];
    for (int i = 0; i < n; i++)
        scanf("%d", &pep[i]);
    for (int I = 0; I < n; I++)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (pep[I] == pep[i])
                ans++;
        if (ans == 1)
            puts("BeiJu");
        else printf("%d\n", ans - 1);
    }
    return 0;
}

/*//ÍøÉÏµÄ
#include <stdio.h>  
int main(void)
{
	int n, m;

	while (scanf("%d", &n) != EOF)
	{
		int M[201] = { 0 };
		int N[1000] = { 0 };
		scanf("%d", &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &N[i]);
			M[N[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (M[N[i]] == 1)
				printf("BeiJu\n");
			else
				printf("%d\n", M[N[i]] - 1);
		}
	}
	return 0;
}*/