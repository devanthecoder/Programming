#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include <pthread.h>
#define N 10
int times;
Queue Q;
pthread_mutex_t makeAtomic = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notF = PTHREAD_COND_INITIALIZER;
pthread_cond_t notE = PTHREAD_COND_INITIALIZER;

void * thread1(void *);
void * thread2(void *);
void Producer() {
    pthread_mutex_lock(&makeAtomic);
    while(isFullQ(Q)){
        printf("Queue is full. Waiting for free space...\n");
        pthread_cond_wait(&notF, &makeAtomic);
    }
    int x = rand();
    printf("Produced: %d\n", x);
    addQ(x, &Q);
    pthread_cond_signal(&notE);
	pthread_mutex_unlock(&makeAtomic);
    
}
void Consumer() {
    pthread_mutex_lock(&makeAtomic);
    while(isEmptyQ(Q)){
        printf("Queue is empty. Waiting for new elements...\n");
        pthread_cond_wait(&notE, &makeAtomic);
    }
    int x = deleteQ(&Q);
    if(x!=-1)printf("Consumed: %d\n", x);
    pthread_cond_signal(&notF);
    pthread_mutex_unlock(&makeAtomic);
}

int main(int count, char *vect[]) { // argument is data for ’times’
    Q = initQ(N+1);
    srand(time(NULL));
    pthread_t thID1, thID2;

    if(count < 2) {
        printf("No argument for times\n");
        exit(0);
    }

    times = atoi(vect[1]);
    pthread_create(&thID1, NULL, thread1, NULL);
    pthread_create(&thID2, NULL, thread2, NULL);
    pthread_join(thID1, NULL);
    pthread_join(thID2, NULL);

    // printf("n: %d\n", n);
    return 0;
}

void *thread1(void *vp) {
    int i;
    for(i=0; i<times; ++i) Producer();
    return NULL;
}

void *thread2(void *vp) {
    int i;
    for(i=0; i<times; ++i) Consumer();
    return NULL;
}