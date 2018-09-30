#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define bool _Bool
bool *findPrime(int n)
{
    bool *table = malloc(n * sizeof(bool));
    memset(table, true, sizeof(table));
    for (int i = 2; i < n; i++)
        if (table[i])
            for (int j = 2 * i; j < n; j += i)
                table[j] = false;
    return table;
}

int countPrimes(int n)
{
    vector<bool> table(n, true);
    table[0] = table[1] = false;
    int limit = sqrt(n);
    for (int i = 2; i <= limit; ++i)
        if (table[i])
            for (int j = i * i; j < n; j += i)
                table[j] = false;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    bool *ans = findPrime(n);
    for (int i = 2; i <= n; i++)
        if (ans[i])
            printf("%d\t", i);
    return 0;
}
