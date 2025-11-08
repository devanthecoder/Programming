#ifndef QUEUE_H
#define QUEUE_H
typedef struct{
    int* Q;
    int Size;
    int Head;
    int Tail;
}Queue;
Queue initQ(int Size);
void addQ(int x, Queue* Q);
int deleteQ(Queue* Q);
int frontQ(Queue Q);
int isEmptyQ(Queue Q);
int isFullQ(Queue Q);
#endif