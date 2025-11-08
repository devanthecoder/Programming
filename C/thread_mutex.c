/**************************************************************
 * Programming with pthread: pthreadProg1.c                   *
 * Compile: cc -Wall -lpthread pthreadProg1.c -o pthreadProg1 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int times, n = 0 ;
pthread_mutex_t makeAtomic = PTHREAD_MUTEX_INITIALIZER;

void * thread1(void *) ;
void * thread2(void *) ;
void inc() {
	pthread_mutex_lock(&makeAtomic);
	int a; 
	a = n; a = a+1; n = a;
	pthread_mutex_unlock(&makeAtomic);

}
void dec() {
	int a; 
	pthread_mutex_lock(&makeAtomic);
	a = n; a = a-1; n = a;
	pthread_mutex_unlock(&makeAtomic);
}

int main(int count, char *vect[]) { // argument is data for ’times’
    pthread_t thID1, thID2;

    if(count < 2) {
        printf("No argument for times\n") ;
        exit(0) ;
    }

    times = atoi(vect[1]) ;
    pthread_create(&thID1, NULL, thread1, NULL) ;
    pthread_create(&thID2, NULL, thread2, NULL) ;
    pthread_join(thID1, NULL) ;
    pthread_join(thID2, NULL) ;

    printf("n: %d\n", n) ;
    return 0 ;
}

void *thread1(void *vp) {
    int i ;
    for(i=1; i<times; ++i) inc() ;
    return NULL ;
}

void *thread2(void *vp) {
    int i ;
    for(i=1; i<times; ++i) dec() ;
    return NULL ;
}
