#include <stdio.h>
#include <stdlib.h>
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
typedef int ElementType;

void Merge(ElementType *a, ElementType *tmparray, int lpos, int rpos, int rend)
{
    int num = rend - lpos + 1;
    int lend = rpos - 1;
    int i = lpos;
    while (lpos <= lend && rpos <= rend)
        tmparray[i++] = (a[lpos] < a[rpos]) ? a[lpos++] : a[rpos++];

    tmparray[i++] = (lpos <= lend) ? a[lpos++] : a[rpos++];
    for (i = 0; i < num; i++, rend--)
        a[rend] = tmparray[rend];
}

void MSort(ElementType *a, ElementType *tmparray, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        MSort(a, tmparray, left, center);
        MSort(a, tmparray, center + 1, right);
        if (a[center] <= a[center + 1])
            return;
        Merge(a, tmparray, left, center + 1, right);
    }
}

void MergeSort(ElementType *a, int n)
{
    int *tmparray = (ElementType *)malloc(sizeof(ElementType) * n);
    if (!tmparray)
        Error("Out of space.");
    MSort(a, tmparray, 0, n - 1);
    free(tmparray);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n <= 1)
        Error("Too little");
    int *a = (ElementType *)malloc(sizeof(ElementType) * n);
    if (!a)
        Error("Out of space.");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]); //
    MergeSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]); //
    getchar();
    getchar();
    return 0;
}

1 import java.util.Arrays;
2 import edu.princeton.cs.algs4.StdRandom;
3 4 public class MergeSortedSubArray
{
    5 private static boolean less(Comparable v, Comparable w)
    {
        6 return v.compareTo(w) < 0;
        7
    }
    8 public static void merge(Comparable[] array)
    {
        9 int n = array.length / 2;
        10 Comparable[] aux = new Comparable[n];
        11 for (int i = 0; i < n; i++)
        { //取左半边sorted的元素至辅助数组,因为未来归并左侧位置可能会被右侧元素占据12 aux[i] = array[i];13 }14 System.out.println(Arrays.toString(aux));15 int l = 0;16 int r = n;17 for(int k = 0; k<2*n;k++){18 if(l >= n) break;//辅助元素数组全部用完,array右侧不需要挪动位置了19 else if(r>=2*n) array[k]=aux[l++];//array原右侧元素全部放置合适位置,后面只需把辅助数组的元素挪到array右侧20 else if(less(array[r],aux[l])) array[k] = array[r++];21 else array[k] = aux[l++];22 }23 }24 25 public static void main(String[] args){26 int n = 10;27 int[] subarray1 = new int[n];28 int[] subarray2 = new int[n];29 for (int i = 0; i < n; i++) {30 subarray1[i] = StdRandom.uniform(100);31 subarray2[i] = StdRandom.uniform(100);32 }33 Arrays.sort(subarray1);34 Arrays.sort(subarray2);35 Integer[] array = new Integer[2*n];36 for(int i = 0; i<n;i++){37 array[i] = subarray1[i];38 array[n+i] = subarray2[i];39 }40 System.out.println(Arrays.toString(array));41 merge(array);42 System.out.println(Arrays.toString(array));43 }44 }