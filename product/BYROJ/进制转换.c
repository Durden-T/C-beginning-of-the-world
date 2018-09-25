//±±” OJ
#include<stdio.h>
char * mitob(int, char);
int main(void)
{
    int sourse;
    char choice;
    scanf("%d %c", &sourse, &choice);
    if (sourse < 0)
    {
        sourse = -sourse;
        putchar('-');
    }
    printf("%s", mitob(sourse,choice));
    return 0;
}
char * mitob(int a, char b)
{
    static char ch[33];
    int i = 1;
    int x = 0;
    int t;
    int jud;
    switch (b)
    {
    case 'B':   t = 2;  break;
    case 'O':   t = 8;  break;
    default:    t = 16;
    }
    for (; a / i; i *= t);+ 
    i /= t;
    if (t != 16)
        for (; i; i /= t, x++)
        {
            ch[x] = (a / i) + '0';
            a %= i;
        }
    else
        for (; i; i /= t, x++)
        {
            jud = a / i;
			ch[x] = jud<10 ? jud+'0' : 'A'+jud-10;
            a %= i;
        }
        ch[x] = '\0';
        return ch;
}