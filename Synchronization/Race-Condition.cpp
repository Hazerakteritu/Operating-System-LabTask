//Race Condition Simulation
// Two threads increment a global counter. 
// Without mutex: result is incorrect due to race condition. 
// With mutex: result is correct. 

#include <bits/stdc++.h> 
using namespace std; 
#include <pthread.h> 
 
int counter = 0; 
pthread_mutex_t lock; 
 
void *increment(void *arg) { 
    for (int i = 0; i < 100000; i++) { 
        pthread_mutex_lock(&lock); 
        counter++; 
        pthread_mutex_unlock(&lock); 
    } 
    return NULL; 
} 
 
int main() { 
    pthread_t t1, t2; 
    pthread_mutex_init(&lock, NULL); 
 
    pthread_create(&t1, NULL, increment, NULL); 
    pthread_create(&t2, NULL, increment, NULL); 
 
    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
 
    printf("Final Counter: %d\n", counter); 
 
    pthread_mutex_destroy(&lock); 
    return 0; 
}