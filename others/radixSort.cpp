
int getMax(vector<int> &a)
{
    int i, max;
    max = a[0];
    for (i = 1; i < a.size(); i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void countSort(vector<int> &a, int exp)
{
    int output[a.size()]; // 存储"被排序数据"的临时数组
    int i, buckets[10] = {0};

    // 将数据出现的次数存储在buckets[]中
    for (i = 0; i < a.size(); i++)
        ++buckets[(a[i] / exp) % 10];

    // 更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    // 将数据存储到临时数组output[]中
    for (i = a.size() - 1; i >= 0; i--)
        output[--buckets[(a[i] / exp) % 10]] = a[i];

    // 将排序好的数据赋值给a[]
    for (i = 0; i < a.size(); i++)
        a[i] = output[i];
}

/*
 * 基数排序
 *
 * 参数说明：
 *     a -- 数组
 *     a.size() -- 数组长度
 */
void radixSort(vector<int> &a)
{
    int exp;             // 指数。当对数组按各位进行排序时，exp=1；按十位进行排序时，exp=10；...
    int max = getMax(a); // 数组a中的最大值

    // 从个位开始，对数组a按"指数"进行排序
    for (exp = 1; max / exp > 0; exp *= 10)
        countSort(a, exp);
}