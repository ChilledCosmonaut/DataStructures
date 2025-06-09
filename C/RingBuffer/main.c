#include <stdio.h>
#include <stdlib.h>

#include "RingBuffer.h"

int main(void) {
    RingBuffer* buffer = CreateRingbuffer(25);
    PrintStatistics(buffer);
    AddData(buffer, "c");
    PrintStatistics(buffer);
    AddData(buffer, "d");
    PrintStatistics(buffer);
    AddData(buffer, "e");
    PrintStatistics(buffer);
    char* test = malloc(sizeof(char));
    PopData(buffer, test);
    PrintStatistics(buffer);
    printf("%s\n", test);
    DequeueData(buffer, test);
    PrintStatistics(buffer);
    printf("%s\n", test);
    return 0;
}