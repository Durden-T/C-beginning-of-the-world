#include <stdio.h>
#include <stdlib.h>
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
typedef int ElementType;
void InsertSort(ElementType *A, int n)
{
    ElementType Tmp;
    for (int p = 1, i; p < n; ++p)
    {
        for (i = p, Tmp = A[p]; i && A[i - 1] > Tmp; --i)
            A[i] = A[i - 1];
        A[i] = Tmp;
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    if (n <= 1)
        Error("Too little");
    int *a = malloc(sizeof(ElementType) * n);
    if (!a)
        Error("Out of space.");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]); //
    InsertSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]); //
    return 0;
}