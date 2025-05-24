//Reader-Writer Problem using Mutex 
// Multiple readers can read simultaneously. 
// Only one writer can write at a time (no reading during write). 
// Use mutex to synchronize access. 


#include <bits/stdc++.h> 
using namespace std; 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
 
int readcount = 0; 
pthread_mutex_t mutex, wrt; 
 
void *reader(void *arg) { 
    pthread_mutex_lock(&mutex); 
    readcount++; 
    if (readcount == 1) 
        pthread_mutex_lock(&wrt); 
    pthread_mutex_unlock(&mutex); 
 
    printf("Reader %d is reading\n", *((int*)arg)); 
    sleep(1); 
 
    pthread_mutex_lock(&mutex); 
    readcount--; 
    if (readcount == 0) 
        pthread_mutex_unlock(&wrt); 
    pthread_mutex_unlock(&mutex); 
 
    return NULL; 
} 
 
void *writer(void *arg) { 
    pthread_mutex_lock(&wrt); 
    printf("Writer %d is writing\n", *((int*)arg)); 
    sleep(2); 
    pthread_mutex_unlock(&wrt); 
    return NULL; 
} 
 
int main() { 
    pthread_t r[5], w[2]; 
    pthread_mutex_init(&mutex, NULL); 
    pthread_mutex_init(&wrt, NULL); 
 
    int reader_ids[5] = {1, 2, 3, 4, 5}; 
    int writer_ids[2] = {1, 2}; 
 
    for (int i = 0; i < 5; i++) 
        pthread_create(&r[i], NULL, reader, &reader_ids[i]); 
 
    for (int i = 0; i < 2; i++) 
        pthread_create(&w[i], NULL, writer, &writer_ids[i]); 
 
    for (int i = 0; i < 5; i++) 
        pthread_join(r[i], NULL); 
 
    for (int i = 0; i < 2; i++) 
        pthread_join(w[i], NULL); 
 
    pthread_mutex_destroy(&mutex); 
    pthread_mutex_destroy(&wrt); 
    return 0; 
}