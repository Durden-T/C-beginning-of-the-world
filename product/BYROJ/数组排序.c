#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return(*(int *)b - *(int *)a);
}
int main(void)
{
    static int ans[100];
    int temp, i;
    scanf("%d", &ans[0]);
    scanf("%d", &ans[1]);
    scanf("%d", &ans[2]);
    scanf("%d", &ans[3]);
    scanf("%d", &ans[4]);
    scanf("%d", &temp);
    qsort(ans, 5, sizeof(int), cmp);
    for (i = 0; i < 5 && ans[i] >= temp; i++);
    for (int a = 0; a < i; a++)
        printf("%d ", ans[a]);
    printf("%d ", temp);
    for (; i < 5; i++)
        printf("%d ", ans[i]);
    return 0;
}