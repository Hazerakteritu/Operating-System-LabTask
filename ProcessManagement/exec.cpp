//CreateProcess using fork() and exec()
//The exec() functions replaces the current process image with a new process image.

#include <bits/stdc++.h>
using namespace std;
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{ 
/*
cout<<"Before "<<endl;
execl("/bin/ls", "ls", "-l", NULL);
cout<<"After"<<endl;

*/

pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    // Child process
    if (pid == 0) {
        printf("Child process running (PID = %d)...\n", getpid());
        
        execl("/bin/ps", "ps", NULL);
        while (1) {
            printf("Child is working...\n");
            sleep(1);
        }
    } 
    // Parent process
    else {
        printf("Parent (PID = %d) created child with PID = %d\n", getpid(), pid);
        sleep(5); 

    }
    return 0;
}
