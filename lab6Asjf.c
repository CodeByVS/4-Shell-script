//SJF(non-preemptive) algorithm implementation in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int p, atime, btime, ct, wt, tat;
    struct node *next;
};

struct node *start = NULL;

void createProcessList(int n)
{
    int i;
    struct node *ptr, *newnode;

    for (i = 1; i <= n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("Process P[%d]\n", i);
        printf("Enter Process ID = ");
        scanf("%d", &newnode->p);
        printf("Enter Arrival time = ");
        scanf("%d", &newnode->atime);
        printf("Enter Burst time = ");
        scanf("%d", &newnode->btime);
        newnode->next = NULL;

        if (start == NULL)
        {
            start = newnode;
            ptr = start;
        }
        else
        {
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
}

void sortProcessList()
{
    struct node *ptr = start, *preptr;
    int temp;

    while (ptr->next != NULL)
    {
        preptr = ptr->next;
        while (preptr != NULL)
        {
            if (ptr->btime > preptr->btime)
            { // swapping the burst time, arrival time, and process ID
                // of the current node (ptr) with that of the subsequent node
                temp = ptr->atime;
                ptr->atime = preptr->atime;
                preptr->atime = temp;

                temp = ptr->btime;
                ptr->btime = preptr->btime;
                preptr->btime = temp;

                temp = ptr->p;
                ptr->p = preptr->p;
                preptr->p = temp;
            }
            preptr = preptr->next;
        }
        ptr = ptr->next;
    }
}

void calculateProcessDetails(int n)
{
    struct node *ptr = start;
    int c = ptr->atime, i;

    while (ptr)
    {
        ptr->ct = c + ptr->btime;
        c = ptr->ct;
        ptr->tat = ptr->ct - ptr->atime;
        ptr->wt = ptr->tat - ptr->btime;
        ptr = ptr->next;
    }
}

void displayFinalTable(int n)
{
    struct node *ptr = start;

    printf("\n\t\tFinal Table of Processes\n");
    printf("ProcessID\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\n");

    while (ptr)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", ptr->p, ptr->atime, ptr->btime, ptr->wt, ptr->tat);
        ptr = ptr->next;
    }
}

void displayAverageWT(int n)
{
    struct node *ptr = start;
    float avgt = 0.0, avgw = 0.0;

    while (ptr != NULL)
    {
        avgt += ptr->tat;
        avgw += ptr->wt;
        ptr = ptr->next;
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

    sortProcessList();
    calculateProcessDetails(n);
    displayFinalTable(n);
    displayAverageWT(n);

    return 0;
}
