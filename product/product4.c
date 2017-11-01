#include<stdio.h>cpp  P371 5
char *mfind(char *str, char n);
int main(void)
{
	char *ch="fuck you ah";
	char *ans = mfind(ch,'k');
	if (ans)
		printf("%c", *ans);
	getchar();
	getchar();
}
char *mfind(char *str, char n)
{
	for (int i = 0; i < sizeof(str)-1; i++)
	{
		if (*(str + i) == n)
			return str + i;
	}
	return NULL;
}








/*char* strchr(char *s, char c)
{
    while(*s != '\0' && *s != c)
    {
        ++s;
    }
    return *s==c ? s : NULL;
}*/
