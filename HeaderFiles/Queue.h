#ifndef _QUEUE_H
#define _QUEUE_H

#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
typedef int ElementType;
typedef struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};
typedef struct QueueRecord *Queue;

Queue CreateQueue(int Capacity);
void DeleteQueue(Queue Q);
bool IsEmpty(Queue Q);
void Enqueue(int x, Queue Q);
ElementType FrontQueue(Queue Q);
ElementType Dequeue(Queue Q);

Queue CreateQueue(int Capacity)
{
    Queue Q = malloc(sizeof(struct QueueRecord));
    Q->Array = malloc(Capacity * sizeof(ElementType));
    Q->Capacity = Capacity;
    Q->Rear = -1;
    Q->Front = Q->Size = 0;
    return Q;
}

void DeleteQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
    Q = NULL;
}

bool IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

void Enqueue(ElementType x, Queue Q)
{
    if (Q->Size + 1 > Q->Capacity)
        Error("Overflow.");
    if (Q->Rear + 1 == Q->Capacity)
        Q->Rear = 0;
    Q->Array[++Q->Rear] = x;
    Q->Size++;
}

ElementType FrontQueue(Queue Q)
{
    return Q->Front;
}
ElementType Dequeue(Queue Q)
{
    Q->Size--;
    Q->Front = (++Q->Front == Q->Capacity) ? 0 : Q->Front;
    return Q->Array[Q->Front];
}

#endif