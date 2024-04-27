//FCFS algorithm implementation in C using structure / linked list

#include <stdio.h>

#define MAX_PROCESS 100

struct node
{
    int p, atime, btime, ct, wt, tat;
};

struct node process[MAX_PROCESS];

void createProcessList(int n)
{
    printf("Enter details for %d processes:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Process P[%d]\n", i + 1);
        printf("Enter Process ID = ");
        scanf("%d", &process[i].p);
        printf("Enter Arrival time = ");
        scanf("%d", &process[i].atime);
        printf("Enter Burst time = ");
        scanf("%d", &process[i].btime);
    }
}

void sortProcessList(int n)
{
    struct node temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (process[j].atime > process[j + 1].atime)
            {
                // swapping the process details
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

void calculateProcessDetails(int n)
{
    // initialize the variable c with the arrival time of the first process
    int c = process[0].atime;
    for (int i = 0; i < n; i++)
    {
        // completion time as sum of current time and burst time of current process
        process[i].ct = c + process[i].btime;
        c = process[i].ct; // update current time
        process[i].tat = process[i].ct - process[i].atime;
        process[i].wt = process[i].tat - process[i].btime;
    }
}

void displayFinalTable(int n)
{
    printf("\n\t\tFinal Table of Processes\n");
    printf("ProcessID\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t%d\t\t%d\n", process[i].p, process[i].atime,
               process[i].btime, process[i].wt, process[i].tat);
    }
}

void displayAverageWT(int n)
{
    float avgt = 0.0, avgw = 0.0;

    for (int i = 0; i < n; i++)
    {
        avgt += process[i].tat;
        avgw += process[i].wt;
    }

    printf("\nAvg Waiting time: %f", avgw / n);
    printf("\nAvg TurnAround time: %f\n", avgt / n);
}

int main()
{
    int n;

    printf("Enter number of Processes: ");
    scanf("%d", &n);

    createProcessList(n);

    sortProcessList(n);
    calculateProcessDetails(n);
    displayFinalTable(n);
    displayAverageWT(n);

    return 0;
}
