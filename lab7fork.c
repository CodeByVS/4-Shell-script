   /* • Discuss basics of round robin algorithm implementation 
    • How to create a processes using fork system call
    • Use of wait function
    • Assignments
        ◦ Create different process tree using fork system call
        ◦ Write a program where a process waits for all its child processes*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void create_process_tree(int max_depth)
{
    for (int depth = 0; depth < max_depth; depth++)
    {
        pid_t child_id = fork();
        if (child_id == 0)
        {
            printf("Child with id: %d and its Parent id: %d\n", getpid(), getppid());
        }
        else
        {
            wait(NULL); // makes the parent process wait for the child process to finish
        }
    }
}

int main()
{
    int parent_id = getpid();
    printf("Parent of all: %d\n", parent_id);
    create_process_tree(3); // depth of the tree

    return 0;
}
