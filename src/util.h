#pragma once
#include "HeapElement.h"

class util
{
public:
    enum Command{
        kStop = 0,
        kCreateHeap = 1,
        kReadFile = 2,
        kWriteHeap = 3,
        kInsert = 4,
        kDeleteMin = 5,
        kDecreaseKey = 6,
        kInvalid = 7
    };

    static Command GetNextCommand(int *args);
    static void getArgs(int *args, int n);
    static int arrayFromFile(HeapElement** arr,const char *filename);
    static void displayUninitializedError();
};
