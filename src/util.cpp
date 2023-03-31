#include "util.h"
#include "HeapElement.h"
#include <iostream>

util::Command util::GetNextCommand(int args[])
{
    char c;
    while (true)
    {
        scanf("%c", &c);
        
        if(c == ' ' || c == '\t' || c == '\n') continue;
        if(c == 's' || c == 'S') 
        {
            std::cout << "COMMAND: S" << std::endl;
            return kStop;
        }
        if(c == 'c' || c == 'C') {
            getArgs(args, 1);
            std::cout << "COMMAND: C " << args[0] << std::endl;
            return kCreateHeap;
        }
        if(c == 'r' || c == 'R') 
        {
            std::cout << "COMMAND: R " << std::endl;
            return kReadFile;
        }
        if(c == 'w' || c == 'W') 
        {
            std::cout << "COMMAND: W" << std::endl;
            return kWriteHeap;
        }
        if(c == 'i' || c == 'I') {
            getArgs(args, 2);
            std::cout << "COMMAND: I " << args[0] << " " << args[1] << std::endl;
            return kInsert;
        }
        if(c == 'd' || c == 'D') {
            getArgs(args, 1);
            std::cout << "COMMAND: D " << args[0] << std::endl;
            return kDeleteMin;
        }
        if(c == 'k' || c == 'K') {
            getArgs(args, 3);
            std::cout << "COMMAND: K " << args[0] << " " << args[1] << " " << args[2] << std::endl;
            return kDecreaseKey;
        }
        std::cout << "INVALID COMMAND" << std::endl;
        return kInvalid;
    }
    
}

void util::getArgs(int *args, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &args[i]);
    }
}

int util::arrayFromFile(HeapElement** arr,const char *filename)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        std::cout << "There was a problem opening file " << filename << "f or reading." << std::endl;
        return 0;
    }

    int size;
    if(!feof(file)) {
        fscanf(file, "%d", &size);
        *arr = (HeapElement*)malloc(size * sizeof(HeapElement));
    }

    int i = 0;
    while(!feof(file))
    {
        HeapElement* element = *arr + i;
        fscanf(file, "%d", &element->key);
        i++;
    }

    if(i < size)
    {
        std::cout << "Sorry!!! It cannot be done. The number of elements in file is less than as specified in the beginning of file." << std::endl;
        *arr = nullptr;
        return 0;
    }
    fclose(file);
    return size;
}

void util::displayUninitializedError()
{
    std::cout << "Sorry!!! It cannot be done. Please initialize the heap first." << std::endl;
}
