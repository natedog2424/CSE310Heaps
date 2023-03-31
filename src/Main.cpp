// main.cpp
// Created by: Nathan Anderson

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Heap.h"
using namespace std;

int main(){
    util::Command command;
    int args[3];
    Heap* heap = nullptr;

    while(true){
        command = util::GetNextCommand(args);
        switch (command)
        {
            case util::kStop: {
                return 0;
                break;
            }
            case util::kCreateHeap: {
                heap = Heap::Initialize(args[0]);
                break;
            }
            case util::kReadFile: {
                if(heap == nullptr){
                    util::displayUninitializedError();
                    break;
                }
                HeapElement* arr = nullptr;
                int size = util::arrayFromFile(&arr, "HEAPinput.txt");
                if (arr != nullptr){
                    Heap::BuildHeap(heap, arr, size);
                }
                free(arr);
                break;
            }
            case util::kWriteHeap: {
                if(heap == nullptr){
                    util::displayUninitializedError();
                    break;
                }
                Heap::PrintHeap(heap);
                break;
            }
            case util::kInsert: {
                if(heap == nullptr){
                    util::displayUninitializedError();
                    break;
                }
                int flag = args[0];
                if(flag != 1 && flag != 2) {
                    cout << "Invalid flag value" << endl;
                    break;
                }
                int key = args[1];
                HeapElement element = {key};
                Heap::Insert(heap, element, (Heap::Flag)flag);
                break;
            }
            case util::kDeleteMin: {
                if(heap == nullptr){
                    util::displayUninitializedError();
                    break;
                }
                int flag = args[0];
                if(flag != 1 && flag != 2) {
                    cout << "Invalid flag value" << endl;
                    break;
                }
                cout << Heap::DeleteMin(heap, (Heap::Flag)flag).key << endl;
                break;
            }
            case util::kDecreaseKey: {
                if(heap == nullptr){
                    util::displayUninitializedError();
                    break;
                }
                int flag = args[0];
                if(flag != 1 && flag != 2) {
                    cout << "Invalid flag value" << endl;
                    break;
                }
                //book/prof input indexes at 0 but we index at 1
                int index = args[1] - 1;
                int newKey = args[2];
                Heap::DecreaseKey(heap, index, newKey, (Heap::Flag)flag);
                break;
            }
            case util::kInvalid: {
                break;
            }
        }
    }
    return 0;
}