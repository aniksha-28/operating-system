#include <stdio.h>

int main()
{
    int blockSize[10], processSize[10];
    int m, n, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    /* First Fit */
    printf("\nFIRST FIT\n");
    int ff[10];
    int temp1[10];

    for(i = 0; i < m; i++)
        temp1[i] = blockSize[i];

    for(i = 0; i < n; i++)
    {
        ff[i] = -1;
        for(j = 0; j < m; j++)
        {
            if(temp1[j] >= processSize[i])
            {
                ff[i] = j;
                temp1[j] -= processSize[i];
                break;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(ff[i] != -1)
            printf("Process %d allocated to Block %d\n", i+1, ff[i]+1);
        else
            printf("Process %d not allocated\n", i+1);
    }

    /* Best Fit */
    printf("\nBEST FIT\n");
    int bf[10];
    int temp2[10];

    for(i = 0; i < m; i++)
        temp2[i] = blockSize[i];

    for(i = 0; i < n; i++)
    {
        int best = -1;

        for(j = 0; j < m; j++)
        {
            if(temp2[j] >= processSize[i])
            {
                if(best == -1 || temp2[j] < temp2[best])
                    best = j;
            }
        }

        bf[i] = best;

        if(best != -1)
            temp2[best] -= processSize[i];
    }

    for(i = 0; i < n; i++)
    {
        if(bf[i] != -1)
            printf("Process %d allocated to Block %d\n", i+1, bf[i]+1);
        else
            printf("Process %d not allocated\n", i+1);
    }

    /* Worst Fit */
    printf("\nWORST FIT\n");
    int wf[10];
    int temp3[10];

    for(i = 0; i < m; i++)
        temp3[i] = blockSize[i];

    for(i = 0; i < n; i++)
    {
        int worst = -1;

        for(j = 0; j < m; j++)
        {
            if(temp3[j] >= processSize[i])
            {
                if(worst == -1 || temp3[j] > temp3[worst])
                    worst = j;
            }
        }

        wf[i] = worst;

        if(worst != -1)
            temp3[worst] -= processSize[i];
    }

    for(i = 0; i < n; i++)
    {
        if(wf[i] != -1)
            printf("Process %d allocated to Block %d\n", i+1, wf[i]+1);
        else
            printf("Process %d not allocated\n", i+1);
    }

    return 0;
}
