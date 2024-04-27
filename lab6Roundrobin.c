//Round robin algorithm implementation in C

#include <stdio.h>

#define MAX 10

struct process
{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int rt; // Remaining burst time
};

int n, q;
struct process p[MAX];

void round_robin()
{
    int completed = 0, current_time = 0;
    int i = 0; // Index for iterating through processes
    while (completed < n)
    {
        if (p[i].rt > 0 && p[i].at <= current_time)
        {
            int execution_time = (p[i].rt < q ? p[i].rt : q);

            p[i].rt -= execution_time;
            current_time += execution_time;

            if (p[i].rt == 0) // process has completed execution
            {
                p[i].tat = current_time - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                completed++;
            }
        }
        i = (i + 1) % n; // Move to the next process in a circular manner
    }
}

void display_result()
{
    float sumWT = 0, sumTAT = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        sumWT += p[i].wt;
        sumTAT += p[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f\n", sumWT / n);
    printf("Average Turnaround Time: %.2f\n", sumTAT / n);
}

int main()
{

    n = 4, q = 6;
    struct process arr[] = {{1, 0, 8}, {2, 1, 5}, {3, 2, 10}, {4, 3, 11}};

    for (int i = 0; i < n; i++)
    {
        p[i].pid = arr[i].pid;
        p[i].at = arr[i].at;
        p[i].bt = arr[i].bt;

        p[i].rt = p[i].bt;
    }

    // printf("Enter the number of processes: ");
    // scanf("%d", &n);

    // printf("Enter time quantum for Round Robin: ");
    // scanf("%d", &q);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
    //     scanf("%d %d", &p[i].at, &p[i].bt);
    //     p[i].pid = i + 1;
    //     p[i].rt = p[i].bt;
    // }

    round_robin();
    display_result();

    return 0;
}
