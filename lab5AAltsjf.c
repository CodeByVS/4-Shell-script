//SJF(non-preemptive) algorithm implementation in C

#include <stdio.h>

#define MAX 50

struct node
{
    int pid, at, bt, ct, tat, wt;
};

struct node p[MAX];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\n", i + 1);
        printf("Enter pid: ");
        scanf("%d", &p[i].pid);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
    }
}

void sort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            struct node temp;
            if (p[j].bt > p[j + 1].bt)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calc(int n)
{
    int c = p[0].at;

    for (int i = 0; i < n; i++)
    {
        p[i].ct = c + p[i].bt;
        c = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void avg(int n)
{
    double avgWT, avgTAT;
    for (int i = 0; i < n; i++)
    {
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("Average wt: %f\n", avgWT / n);
    printf("Average tat: %f\n", avgTAT / n);
}

void display(int n)
{
    printf("processID\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }
}

int main()
{
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    init(n);
    sort(n);

    calc(n);

    display(n);
    avg(n);

    return 0;
}
