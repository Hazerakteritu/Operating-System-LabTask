//Using fork 
// child is a duplicate of the parent process.
//getpid() returns the current process ID.
//getppid() returns the parent process ID.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t q;
    printf("Before fork\n");
    q = fork();

    if(q < 0)
        printf("Error\n");

    else if(q == 0) {
        printf("I am a Child having pid %d\n", getpid());
        printf("My Parent's pid is   %d\n", getppid());
    }
    else {
        wait(NULL);  // Wait for child to finish
        printf("Parent having  pid is   %d\n", getpid());
        printf("My Child's pid is   %d\n", q);
    }

    return 0;
}