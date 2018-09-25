#include <stdio.h>
#include <stdlib.h>
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
#define CUTOFF 3

void InsertSort(int *nums, int n)
{
    int Tmp;
    for (int p = 1, i; p < n; p++)
    {
        for (i = p, Tmp = nums[p]; i && nums[i - 1] > Tmp; i--)
            nums[i] = nums[i - 1];
        nums[i] = Tmp;
    }
}

int Median3(int *nums, int left, int right)
{
    int center = (left + right) / 2;
    if (nums[left] > nums[center])
        swap(nums[left], nums[center]);
    if (nums[left] > nums[right])
        swap(nums[left], nums[right]);
    if (nums[right] < nums[center])
        swap(nums[right], nums[center]);
    swap(nums[center], nums[right - 1]);
    return nums[right - 1];
}

void QuickSort(int *nums, int left, int right)
{
    if (left + CUTOFF <= right)
    {
        int pivot = Median3(nums, left, right);
        int i = left, j = right - 1;
        while (1)
        {
            while (nums[++i] < pivot)
                ;
            while (nums[--j] > pivot)
                ;
            if (i < j)
                swap(nums[i], nums[j]);
            else
                break;
        }
        swap(nums[i], nums[right - 1]);
        QuickSort(nums, left, i - 1);
        QuickSort(nums, i + 1, right);
    }
    else
        InsertSort(nums + left, right - left + 1);
}

void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int pos = end;
    for (int i = end; i > start; --i)
        if (nums[i] > nums[start])
            swap(nums[i], nums[pos--]);
    swap(nums[pos], nums[start]);
    quickSort(nums, start, pos - 1);
    quickSort(nums, pos + 1, end);
}

void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int i = start, j = end + 1;
    while (true)
    {
        while (i != end && nums[++i] < nums[start])
            ;
        while (nums[--j] > nums[start])
            ;
        if (i >= j)
            break;
        swap(nums[i], nums[j]);
    }
    swap(nums[start], nums[j]);
    quickSort(nums, start, j - 1);
    quickSort(nums, j + 1, end);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    if (n <= 1)
        Error("Too little");
    int *a = (int *)malloc(sizeof(int) * n);
    if (!a)
        Error("Out of space."); //
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]); //
    return 0;
}
