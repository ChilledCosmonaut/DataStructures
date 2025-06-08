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
    printf("%s\n", test);
    PrintStatistics(buffer);
    DequeueData(buffer, test);
    printf("%s\n", test);
    PrintStatistics(buffer);
    return 0;
}