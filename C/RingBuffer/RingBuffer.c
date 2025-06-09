#include <stdlib.h>
#include "RingBuffer.h"

#include <stdio.h>

RingBuffer* CreateRingbuffer(const long size) {
    RingBuffer* ringbuffer = malloc(sizeof(RingBuffer));
    ringbuffer->size = size;
    ringbuffer->head = 0;
    ringbuffer->tail = 0;
    ringbuffer->start = (char*)malloc(size*sizeof(char));
    return ringbuffer;
}

void AddData(RingBuffer* buffer, const char* data) {
    *(buffer->start + buffer->head) = *data;
    buffer->head++;

    if (buffer->head >= buffer->size) buffer->head = 0;
    if (buffer->head == buffer->tail) buffer->tail++;
}

void PopData(RingBuffer* buffer, char* const DataSpot) {
    if (buffer->head == buffer->tail) return;
    if (buffer->head == 0) buffer->head = buffer->size;

    buffer->head--;
    *DataSpot = *(buffer->start + buffer->head);
}

void DequeueData(RingBuffer* buffer, char* const DataSpot) {
    if (buffer->head == buffer->tail) return;

    *DataSpot = *(buffer->start + buffer->tail);

    buffer->tail++;
    if (buffer->tail >= buffer->size) buffer->tail = 0;
}

void PrintStatistics(RingBuffer* buffer) {
    printf("Ringbuffer head: %ld\nRingbuffer tail: %ld\n Ringbuffer size: %ld\n", buffer->head, buffer->tail, buffer->size);
}