/**
 * Deadlock Demonstration Program written in C.
 * Author: ubdussamad <ubdussamad@gmail.com>
 * Ref: 29OCT2020
 * Under CC-SA License.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ENABLE_C_USAGE_ 1
#include "logX.hpp"

#define NUM_LOOPS 8
long long int sum = 0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

void *shared_print( void *arg ) {
    char * string = (char *) arg;
    for (int i = 0; i < NUM_LOOPS; i++) {
    printf("Thread: %s and id is: %d \n", string , i);
    sleep(1);
    }
    return (NULL);
}

void *counting_function1 ( void *arg ) {
    int offset = *(int *) arg;
    for (int i = 0; i < NUM_LOOPS; i++)
    {   
        // Critical Section
        pthread_mutex_lock(&mutex1); // Locking this Section
        pthread_mutex_lock(&mutex2);
        sum += offset;
        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex1);
    }

    pthread_exit(NULL);
}

void *counting_function2 ( void *arg ) {
    int offset = *(int *) arg;
    for (int i = 0; i < NUM_LOOPS; i++)
    {   
        // Critical Section
        pthread_mutex_lock(&mutex2);
        pthread_mutex_lock(&mutex1); // Locking this Section
        sum += offset;

        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex2);
    }

    pthread_exit(NULL);
}

int main ( void )  {
    char  str[] = "1";
    pthread_t id3;
    // pthread_create( &id3, NULL, shared_print, (void *) str );
    
    pthread_t  id1;int offset_1 = 1;
    pthread_create( &id1 , NULL , counting_function1 , (void *) &offset_1 );
    pthread_t  id2;int offset_2 = -1;
    pthread_create( &id2 , NULL , counting_function2 , (void *) &offset_2);
    pthread_join(id1, NULL);pthread_join(id2, NULL);

    sleep(1);
    printf( ERROR_COLOR_RED_BEGIN_ "Sum is: %lld\n" CLEAR_COLOR_ , sum);
    pthread_join(id3, NULL);
    return(0);
}