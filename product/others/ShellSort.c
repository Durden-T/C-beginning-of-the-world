#include <stdio.h>
#include <stdlib.h>
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
typedef int ElementType;
void ShellSort(ElementType *A, int n)
{
    ElementType Tmp;
    for (int gap = n / 2, i, j; gap; gap /= 2)
        for (i = gap; i < n; ++i)
        {
            for (j = i, Tmp = A[i]; j >= gap && A[j - gap] > Tmp; j -= gap)
                A[j] = A[j - gap];
            A[j] = Tmp;
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
    ShellSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]); //
    return 0;
}
