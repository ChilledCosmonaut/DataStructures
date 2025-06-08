#ifndef RINGBUFFER_H
#define RINGBUFFER_H

typedef struct {
    ulong size;
    ulong head;
    ulong tail;
    char* start;
} RingBuffer;

// Function declarations
RingBuffer* CreateRingbuffer(long size);
void AddData(RingBuffer* buffer, const char* data);
void PopData(RingBuffer* buffer, char* const DataSpot);
void DequeueData(RingBuffer* buffer, char* const DataSpot);
void PrintStatistics(RingBuffer* buffer);

#endif //RINGBUFFER_H
