#pragma once
#include "HeapElement.h"

class Heap
{
private:
    static void Resize(Heap* heap, int n);
public:
    enum Flag {
        kNoPrint = 1,
        kPrint = 2,
    };

    Heap();
    ~Heap();
    int capacity, size;
    bool isValid();
    HeapElement *H;
    static Heap* Initialize(int n);
    static void BuildHeap(Heap* heap, HeapElement arr[], int n);
    static void MinHeapify(Heap* heap, int i);
    static int GetLeftIndex(int i);
    static int GetRightIndex(int i);
    static int GetParentIndex(int i);
    static void Insert(Heap* heap, HeapElement k, Flag flag = kNoPrint);
    static HeapElement DeleteMin(Heap* heap, Flag flag = kNoPrint);
    static void DecreaseKey(Heap* heap, int index, int value, Flag flag = kNoPrint);
    static void PrintHeap(Heap* heap);
};
