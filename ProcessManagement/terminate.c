#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    // Child process
    if (pid == 0) {
        printf("Child process running (PID = %d)...\n", getpid());
        while (1) {
            printf("Child is working...\n");
            sleep(1);
        }
    } 
    // Parent process
    else {
        printf("Parent (PID = %d) created child with PID = %d\n", getpid(), pid);
        sleep(5); 

        // Terminate the child process
        printf("Parent terminating child process...\n");
        kill(pid, SIGTERM); // or SIGKILL for forceful termination

        // wait for child to clean up
        wait(100);
        printf("Child terminated.\n");
    }

    return 0;
}
