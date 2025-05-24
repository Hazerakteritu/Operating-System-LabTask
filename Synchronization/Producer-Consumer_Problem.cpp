// Producer-Consumer Problem using Semaphore 
// Shared buffer of fixed size. 
// Producer adds items; consumer removes items. 
// Use sem_t full, empty and mutex to prevent race conditions. 


#include <bits/stdc++.h> 
using namespace std; 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

#define SIZE 5 
int buffer[SIZE], in = 0, out = 0; 
 
pthread_mutex_t mutex; 
sem_t full, empty; 
 
void *producer(void *arg) { 
    int item; 
    for (int i = 0; i < 10; i++) { 
        item = rand() % 100; 
 
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex); 
 
        buffer[in] = item; 
        printf("Produced: %d\n", item); 
        in = (in + 1) % SIZE; 
 
        pthread_mutex_unlock(&mutex); 
        sem_post(&full); 
        sleep(1); 
    } 
    return NULL; 
} 
 
void *consumer(void *arg) { 
    int item; 
    for (int i = 0; i < 10; i++) { 
        sem_wait(&full); 
        pthread_mutex_lock(&mutex); 
 
        item = buffer[out]; 
        printf("Consumed: %d\n", item); 
        out = (out + 1) % SIZE; 
 
        pthread_mutex_unlock(&mutex); 
        sem_post(&empty); 
        sleep(2); 
    } 
    return NULL; 
} 
 
int main() { 
    pthread_t prod, cons; 
 
    pthread_mutex_init(&mutex, NULL); 
    sem_init(&full, 0, 0); 
    sem_init(&empty, 0, SIZE); 
 
    pthread_create(&prod, NULL, producer, NULL); 
    pthread_create(&cons, NULL, consumer, NULL); 
 
    pthread_join(prod, NULL); 
    pthread_join(cons, NULL); 
 
    pthread_mutex_destroy(&mutex); 
    sem_destroy(&full); 
    sem_destroy(&empty); 
 
    return 0; 
} 