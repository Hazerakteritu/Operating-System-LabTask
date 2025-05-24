//Parameter Passing 
// program to create thread. Thread prints 0-4 while the main process prints 20-24 

#include <bits/stdc++.h>
using namespace std;
#include<unistd.h> 
#include<pthread.h> 

void *thread1_func(void *arg); 
int i,n, j; 

int main(){ 
    pthread_t a;    
    void *result; 
    int num[2] = {3, 5}; 
    pthread_create(&a, NULL, thread1_func, (void *)num);  
    pthread_join(a, &result);    // process waits for thread to finish 
    printf("Inside Main Process\n"); 
    printf("Thread1 returned: %s\n", (char *)result); 
} 
 
void *thread1_func(void *arg){ 
    printf("Inside Thread1\n"); 
 
    int *x = arg; 
    int sum = x[0] + x[1]; 
    printf("Sum is %d\n", sum); 
    pthread_exit("Sum calculated"); 
}