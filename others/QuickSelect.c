//kth largest
int findKthLargest(vector<int> &nums, int k)
{
    k = nums.size() - k;
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int p = partition(nums, start, end);
        if (p == k)
            break;
        if (p < k)
            start = p + 1;
        else
            end = p - 1;
    }
    return nums[k];
}

int partition(vector<int> &nums, int start, int end)
{
    int pos = start;
    for (int i = start; i < end; i++)
        if (nums[i] < nums[end])
            swap(nums[i], nums[pos++]);
    swap(nums[pos], nums[end]);
    return pos;
}

//kth smallest
#include <stdio.h>
#include <stdlib.h>
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
typedef int ElementType;
#define Swap(a, b)           \
    {                        \
        ElementType SwapTmp; \
        SwapTmp = (a);       \
        (a) = (b);           \
        (b) = SwapTmp;       \
    }
#define CUTOFF 3

void InsertSort(ElementType *A, int n)
{
    ElementType Tmp;
    for (int p = 1, i; p < n; p++)
    {
        for (i = p, Tmp = A[p]; i && A[i - 1] > Tmp; i--)
            A[i] = A[i - 1];
        A[i] = Tmp;
    }
}

ElementType Median3(ElementType *A, int left, int right)
{
    int center = (left + right) / 2;
    if (A[left] > A[center])
        Swap(A[left], A[center]);
    if (A[left] > A[right])
        Swap(A[left], A[right]);
    if (A[right] < A[center])
        Swap(A[right], A[center]);
    Swap(A[center], A[right - 1]);
    return A[right - 1];
}

void QuickSelect(ElementType *A, int k, int left, int right)
{
    if (left + CUTOFF <= right)
    {
        ElementType pivot = Median3(A, left, right);
        int i = left, j = right - 1;
        while (1)
        {
            while (A[++i] < pivot)
                ;
            while (A[--j] > pivot)
                ;
            if (i < j)
                Swap(A[i], A[j]) else break;
        }
        Swap(A[i], A[right - 1]);
        if (k <= i)
            QuickSelect(A, k, left, i - 1);
        else if (k > i + 1)
            QuickSelect(A, k, i + 1, right);
    }
    else
        InsertSort(A + left, right - left + 1);
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (n <= 1)
        Error("Too little");
    int *a = malloc(sizeof(ElementType) * n);
    if (!a)
        Error("Out of space."); //
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    QuickSelect(a, k, 0, n - 1);
    printf("%d", a[k - 1]); //
    return 0;
}
