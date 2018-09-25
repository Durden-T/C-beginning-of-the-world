class Solution
{
  public:
    inline int left(int idx)
    {
        return idx << 1 + 1;
    }
    inline int right(int idx)
    {
        return idx << 1 + 2;
    }
    void max_heapify(vector<int> &nums, int idx)
    {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest])
            largest = l;
        if (r < heap_size && nums[r] > nums[largest])
            largest = r;
        if (largest != idx)
        {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int> &nums)
    {
        heap_size = nums.size();
        for (int i = nums.size() >> 1 - 1; i >= 0; --i)
            max_heapify(nums, i);
    }

  private:
    int heap_size;
}

#ifndef _BinHeap_H
#define _BinHeap_H
//Min heap
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
#define MINDATA INT_MIN //�޸ļǵ�
typedef int ElementType;
struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};
typedef struct HeapStruct *BinHeap;

BinHeap Initialize(int n);
inline void PercolateUp(int pos, BinHeap H);
inline void PercolateDown(int pos, BinHeap H);
void Insert(ElementType X, BinHeap H);
ElementType DeleteMin(BinHeap H);
ElementType DecreaseKey(int pos, ElementType deta, BinHeap H);
ElementType IncreaseKey(int pos, ElementType deta, BinHeap H);
ElementType Delete(int pos, BinHeap H);
BinHeap BuildHeap(ElementType *values, int n);

BinHeap Initialize(int n)
{
    BinHeap H;
    H = malloc(sizeof(struct HeapStruct));
    if (!H)
        Error("Out of space");
    H->Elements = malloc(sizeof(ElementType) * (n + 1));
    if (!H->Elements)
        Error("Out of space");
    H->Capacity = n;
    H->Size = 0;
    H->Elements[0] = MINDATA;
    return H;
}

inline void PercolateUp(int pos, BinHeap H)
{
    while (pos > 1 && H->Elements[pos] < H->Elements[pos / 2])
    {
        swap(H->Elements[pos], H->Elements[pos / 2]);
        pos /= 2;
    }
}

inline void PercolateDown(int pos, BinHeap H)
{
    while (2 * pos <= H->Size)
    {
        int child = 2 * pos;
        if (H->Elements[child + 1] < H->Elements[child])
            ++child;
        if (H->Elements[child] >= H->Elements[pos])
            break;
        swap(H->Elements[pos], H->Elements[child]);
        pos = child;
    }
}

void Insert(ElementType X, BinHeap H)
{
    if (H->Size == H->Capacity)
        Error("Priority queue is full.");
    H->Elements[++H->Size] = X;
    PercolateUp(H->Size, H);
}

ElementType DeleteMin(BinHeap H)
{
    ElementType min = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown(1, H);
    return min;
}

ElementType DecreaseKey(int pos, ElementType deta, BinHeap H)
{
    ElementType tmp = (H->Elements[pos] -= deta);
    PercolateUp(pos, H);
    return tmp;
}

ElementType IncreaseKey(int pos, ElementType deta, BinHeap H)
{
    ElementType tmp = (H->Elements[pos] -= deta);
    PercolateDown(pos, H);
    return tmp;
}

ElementType Delete(int pos, BinHeap H)
{
    int deleted = H->Elements[pos];
    DecreaseKey(pos, H->Elements[pos] - MINDATA, H);
    DeleteMin(H);
    return deleted;
}

BinHeap BuildHeap(ElementType *values, int n)
{
    BinHeap H = Initialize(n);
    H->Size = n;
    for (int i = 1; i <= n; i++)
        H->Elements[i] = values[i - 1];
    for (int i = n / 2; i; i--)
        PercolateDown(i, H);
    return H;
}
#endif
