//Write a program where a process waits for all its child processes

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Hello from child\n");
    }
    else
    {
        // Parent process
        printf("Hello from parent\n");
        wait(NULL); // Wait for child to terminate
        printf("Child has terminated\n");
    }

    printf("Bye\n"); // --process terminates

    return 0;
}
