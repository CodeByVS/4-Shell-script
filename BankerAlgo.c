#include <stdio.h>

#define P 5
#define R 3

int is_safe(int alloc[][R], int max[][R], int avail[])
{
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j]; // Calculate the need for each process

    int finish[P]; // Array to track if a process is finished
    for (int i = 0; i < P; i++)
        finish[i] = 0;

    int SafeSequence[P], idx = 0; // Array to store the safe sequence and current index

    int count = 0;
    while (count < P) // Try to find a safe sequence
    {
        for (int i = 0; i < P; i++)
        {
            if (finish[i] == 0) // If P(i) not finished then finish it
            {
                int can_execute = 1;        // Assume P(i) can be allocated resources it needs
                for (int j = 0; j < R; j++) // Check if all resources for  i are avail
                {
                    if (need[i][j] > avail[j]) // process can only execute if need[i][j] <= avail[j]
                    {
                        can_execute = 0; // flag set to false if for any R(j) need(i) is not met
                        break;
                    }
                }

                if (can_execute)
                {
                    for (int j = 0; j < R; j++)
                        avail[j] += alloc[i][j]; // Update avail resources
                    SafeSequence[idx++] = i;     // Add process i to the safe sequence
                    finish[i] = 1;               // Mark P(i) as finished
                    count++;                     // Increase count for finished process
                }
            }
        }
    }
    // Check if a safe sequence was found
    for (int i = 0; i < P; i++)
    {
        if (finish[i] == 0) // Process i is not finished
        {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }
    // Print the safe sequence if found
    printf("Safe Sequence:");
    for (int i = 0; i < P; i++)
    {
        printf(" P%d", SafeSequence[i]);
        if (i != P - 1)
            printf(" ->");
    }
    printf("\n");
    return 1;
}

int request_resource(int alloc[][R], int max[][R], int avail[], int process_num, int request[])
{
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j]; // Calculate the need for each process

    for (int i = 0; i < R; i++)
        if (request[i] > need[process_num][i] || request[i] > avail[i])
            return 0;

    for (int i = 0; i < R; i++) // grant the request
    {
        avail[i] -= request[i];
        need[process_num][i] -= request[i];
        alloc[process_num][i] += request[i];
    }

    if (is_safe(alloc, max, avail)) // If safe state then return 1
        return 1;
    // Unsafe state
    for (int i = 0; i < R; i++) // Undo the resource alloc
    {
        avail[i] += request[i];
        need[process_num][i] += request[i];
        alloc[process_num][i] -= request[i];
    }
    return 0;
}

int main()
{
    int alloc[P][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; // alloc Matrix
    int max[P][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};   // Max Matrix
    int avail[R] = {3, 3, 2};                                                  // avail Resources

    is_safe(alloc, max, avail);

    int process_num = 4;
    int request[R] = {3, 3, 0};

    if (request_resource(alloc, max, avail, process_num, request))
    {
        printf("Request granted.\n");
    }
    else
    {
        printf("Request denied.\n");
    }

    return 0;
}
