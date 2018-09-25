#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char key[51];
    int x = 0, l;
    int df, xf, nf, tf;
    static int af[5];
    while (scanf("%s", key) && (l = strlen(key)) && strncmp("END", key, l))
    {
        if (l > 7)
        {
            df = xf = nf = tf = 0;
            for (int i = 0; i < l; i++)
            {
                if (df == 0 && isupper(key[i]))
                    df = 1;
                if (xf == 0 && islower(key[i]))
                    xf = 1;
                if (nf == 0 && isdigit(key[i]))
                    nf = 1;
                if (tf == 0 && strchr("~!@#$%^&*()-=",key[i]))
                    tf = 1;
                if ((df + xf + nf + tf) > 2)
                {
                    af[x] = 1;
                    break;
                }
            }
        }
        x++;
    }
    for (int i = 0; i < x; i++)
    {
        if (af[i])
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}