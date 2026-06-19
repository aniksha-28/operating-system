#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], pr[n];
    int wt[n], tat[n];

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i]; // Remaining time
    }

    while(completed < n)
    {
        int highest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(highest == -1 || pr[i] < pr[highest])
                    highest = i;
            }
        }

        if(highest == -1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            completed++;

            tat[highest] = time - at[highest];
            wt[highest] = tat[highest] - bt[highest];
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
