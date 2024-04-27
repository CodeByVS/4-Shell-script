//Preemptive SJF algorithm implementation in C using structure / linked list

#include <stdio.h>
#include <limits.h>
#define MAX 50

struct process
{
    int pid;
    int at;
    int bt;
    int tat;
    int wt;
    int rt; // Remaining time to complete the process
    int finished;
};

struct process p[MAX];
int n;

void sort_by_arrival_time()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            struct process temp;
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int get_min_rt(int cur_time)
{
    int min_index = -1, min_rt = INT_MAX;
    for (int i = 0; i < n; i++) // iterates through each process
                                // finding the index of the process with the minimum remaining burst time among the processes that have arrived and not yet finished
    {
        if (!p[i].finished && p[i].at <= cur_time && p[i].rt < min_rt)
        {
            min_rt = p[i].rt;
            min_index = i;
        }
    }
    return min_index;
}

void preemptive_sjf()
{
    int completed = 0, cur_time = 0;
    while (completed < n) // Loop until all processes are completed
    {
        int min = get_min_rt(cur_time);

        if (min == -1) // no process available
        {
            printf("No process available at time %d\n", cur_time);
            continue;
        }

        p[min].rt--; // Process available -> reduce rt
        cur_time++;

        if (p[min].rt == 0) // process has completed execution
        {
            p[min].tat = cur_time + 1 - p[min].at;
            p[min].wt = p[min].tat - p[min].bt;
            p[min].finished = 1;
            completed++; // Increment the count of completed processes
        }
    }
}

void display()
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
    n = 5;
    struct process arr[] = {{1, 2, 6}, {2, 5, 2}, {3, 1, 8}, {4, 0, 3}, {5, 4, 4}};

    for (int i = 0; i < n; i++)
    {
        p[i].pid = arr[i].pid;
        p[i].at = arr[i].at;
        p[i].bt = arr[i].bt;

        p[i].rt = p[i].bt;
        p[i].finished = 0;
    }

    // printf("Enter number of processes: ");
    // scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
    //     scanf("%d %d", &p[i].at, &p[i].bt);
    //     p[i].pid = i + 1;
    //     p[i].rt = p[i].bt;
    //     p[i].finished = 0;
    // }

    sort_by_arrival_time();
    preemptive_sjf();
    display();

    return 0;
}
