#include <bits/stdc++.h>
using namespace std;
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* task1(void*) {
    pthread_mutex_lock(&mutex1);
    cout << "Task 1 locked mutex1" << endl;

    sleep(1); // Simulate work

    pthread_mutex_lock(&mutex2);
    cout << "Task 1 locked mutex2" << endl;

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    return nullptr;
}

void* task2(void*) {
    pthread_mutex_lock(&mutex2);
    cout << "Task 2 locked mutex2" << endl;

    sleep(1); // Simulate work

    pthread_mutex_lock(&mutex1);
    cout << "Task 2 locked mutex1" << endl;

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    return nullptr;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, nullptr, task1, nullptr);
    pthread_create(&t2, nullptr, task2, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    return 0;
}
