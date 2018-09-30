#ifndef _HashQuad_H
#define _HashQuad_H

#define MinTableSize 10
#define Error(Str) fprintf(stderr, "%s\n", Str), exit(1)
enum KindOfEntry
{
    Legitimate,
    Empty,
    Deleted
};
typedef int ElementType;
typedef unsigned int Index;
struct HashNode
{
    ElementType Element;
    int Info;
};
typedef struct HashNode *Cell;
struct HashTbl
{
    int TableSize;
    int Count;
    Cell Cells;
};
typedef struct HashTbl *HashTable;

static int NextPrime(int N);
Index Hash(ElementType Key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Index Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
HashTable Rehash(HashTable H);

static int NextPrime(int N)
{
    int i;
    if (N % 2 == 0)
        N++;
    for (;; N += 2)
    {
        for (i = 3; i * i <= N; i += 2)
            if (N % i == 0)
                goto ContOuter;
        return N;
    ContOuter:;
    }
}

Index Hash(ElementType Key, int TableSize)
{
    return Key % TableSize;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    H->TableSize = TableSize;
    int i;
    H = malloc(sizeof(struct HashTbl) + sizeof(Cell) * H->TableSize);
    if (!H || !H->Cells)
        Error("Out of space");
    for (i = 0; i < H->TableSize; i++)
        H->Cells[i].Info = Empty;
    H->Count == 0;
    return H;
}

Index Find(ElementType Key, HashTable H)
{
    Index CurrentPos;
    int CollisionNum;
    CollisionNum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    while (H->Cells[CurrentPos].Info != Empty &&
           H->Cells[CurrentPos].Element != Key)
    /* Probably need strcmp!! */
    {
        CurrentPos += 2 * ++CollisionNum - 1;
        if (CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
    if (H->Count >= H->TableSize / 2)
        H = Rehash(H);
    Index Pos;
    Pos = Find(Key, H);
    if (H->Cells[Pos].Info != Legitimate)
    {
        H->Cells[Pos].Info = Legitimate;
        H->Cells[Pos].Element = Key;
        H->Count++;
        /* Probably need strcpy! */
    }
}

HashTable Rehash(HashTable H)
{
    int i, OldSize;
    Cell *OldCells;

    OldCells = H->Cells;
    OldSize = H->TableSize;
    H = InitializeTable(2 * OldSize);
    for (i = 0; i < OldSize; i++)
        if (OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H);
    free(OldCells);
    return H;
}
#endif
