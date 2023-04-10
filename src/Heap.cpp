#include "Heap.h"
#include <iostream>
#include <climits>

using namespace std;

void Heap::Resize(Heap* heap, int n)
{
    if (n <= heap->capacity) {
        return;
    }

    void *new_arr = realloc(heap->H, n * sizeof(HeapElement));
    if (new_arr != nullptr){
        heap->H = (HeapElement *)new_arr;
    } else {
        //copy array to new array
        HeapElement *new_arr = new HeapElement[n];
        for(int i = 0; i < heap->size; i++){
            new_arr[i] = heap->H[i];
        }
        delete[] heap->H;
        heap->H = new_arr;
    }

    heap->capacity = n;
}

Heap::Heap()
{
    capacity = 0;
    size = 0;
}

Heap::~Heap()
{
    
}

bool Heap::isValid()
{
    return capacity > 0;
}

Heap* Heap::Initialize(int n)
{
    Heap *heap = new Heap();
    heap->capacity = n;
    heap->size = 0;
    heap->H = new HeapElement[n];
    return heap;
}

void Heap::BuildHeap(Heap* heap, HeapElement arr[], int arr_size)
{
    if (arr_size > heap->capacity) {
        //Heap::Resize(heap, arr_size);
        cout << "Sorry!!! It cannot be done. Please increase the capacity of heap first." << endl;
        return;
    }

    //copy array to heap
    for(int i = 0; i < arr_size; i++){
        heap->H[i].key = arr[i].key;
    }
    heap->size = arr_size;

    for(int i = (arr_size-1)/2; i >= 0; i--){
        Heap::MinHeapify(heap, i);
    }
}

void Heap::MinHeapify(Heap* heap, int i)
{
    int l = Heap::GetLeftIndex(i);
    int r = Heap::GetRightIndex(i);
    
    if (l > heap->size - 1) {
        return;
    }

    int smallest;
    if(heap->H[l].key < heap->H[i].key) smallest = l;
    else smallest = i;

    if(r <= heap->size - 1 && heap->H[r].key < heap->H[smallest].key) smallest = r;

    if(smallest != i){
        HeapElement temp = heap->H[i];
        heap->H[i] = heap->H[smallest];
        heap->H[smallest] = temp;
        Heap::MinHeapify(heap, smallest);
    }
}

int Heap::GetLeftIndex(int i)
{
    return 2*i + 1;
}

int Heap::GetRightIndex(int i)
{
    return 2*i + 2;
}

int Heap::GetParentIndex(int i)
{
    return (i-1)/2;
}

void Heap::Insert(Heap* heap, HeapElement k, Flag flag)
{
    if(flag == kPrint) Heap::PrintHeap(heap);

    if(heap->size == heap->capacity){
        //Find nearest power of 2 using bit twiddling described here:
        //https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2

        unsigned int v = heap->capacity;
        v--;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        v++;
        Heap::Resize(heap, v);
    }

    int key = k.key;
    int i = heap->size;
    heap->size++;
    heap->H[i].key = INT_MAX;
    Heap::DecreaseKey(heap, i, key, kNoPrint);

    if(flag == kPrint) Heap::PrintHeap(heap);
}

HeapElement Heap::DeleteMin(Heap* heap, Flag flag)
{
    if(heap->size < 1){
        cout << "No elements to remove" << endl;
        return HeapElement();
    }

    if(flag == kPrint) Heap::PrintHeap(heap);

    HeapElement min = heap->H[0];
    heap->H[0] = heap->H[heap->size - 1];
    heap->size--;
    Heap::MinHeapify(heap, 0);

    if(flag == kPrint) Heap::PrintHeap(heap);

    return min;
}

void Heap::DecreaseKey(Heap* heap, int index, int value, Flag flag)
{

    if(index > heap->size - 1) {
        cout << "There are only " << heap->size << " elements in this heap. Hence this operation cannot be completed" << endl;
        return;
    }

    if (value > heap->H[index].key) {
        cout << value << " cannot be larger than the current value in heap at index " << index + 1 << endl;
        return;
    }
    if(flag == kPrint) Heap::PrintHeap(heap);

    while(index > 0 && heap->H[Heap::GetParentIndex(index)].key > value){
        heap->H[index] = heap->H[Heap::GetParentIndex(index)];
        index = Heap::GetParentIndex(index);
    }
    heap->H[index].key = value;

    if(flag == kPrint) Heap::PrintHeap(heap);
}

void Heap::PrintHeap(Heap* heap)
{
    cout << "The capacity is " << heap->capacity << "." << endl;
    cout << "Size is " << heap->size << "." << endl;
    if(heap->size > 0){
        for(int i = 0; i < heap->size; i++){
            cout << heap->H[i].key << "\n";
        }
        cout << endl;
    }
}
