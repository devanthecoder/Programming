#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
Queue initQ(int Size){
    Queue Q;
    Q.Q = (int *)calloc(Size, sizeof(int));
    Q.Head = 0;
    Q.Tail = 0;
    Q.Size = Size;
    return Q;
}
int isEmptyQ(Queue Q){
    if(Q.Head==Q.Tail) return 1;
    else return 0;
}
int isFullQ(Queue Q){
    if(Q.Head==(Q.Tail+1)%Q.Size) return 1;
    else return 0;
}
void addQ(int x, Queue* Q){
    // sleep(2);
    Q->Q[Q->Tail] = x;
    Q->Tail = (Q->Tail+1)%Q->Size;
}
int deleteQ(Queue* Q){
    int x = Q->Q[Q->Head];
    Q->Head = (Q->Head+1)%Q->Size;
    return x;
}
int frontQ(Queue Q){
    if(isEmptyQ(Q)){
        printf("ERROR! Queue is empty.\n");
        return -1;
    }
    else return Q.Q[Q.Head];
}