#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[50], n, head, size;
    int i, j, temp, totalSeek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    /* Sort requests */
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(req[j] > req[j + 1])
            {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int pos;
    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d", head);

    /* Move towards higher tracks */
    for(i = pos; i < n; i++)
    {
        totalSeek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    /* Move to disk end */
    totalSeek += abs((size - 1) - head);
    head = size - 1;
    printf(" -> %d", head);

    /* Reverse direction */
    for(i = pos - 1; i >= 0; i--)
    {
        totalSeek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", totalSeek);
    printf("\nAverage Seek Time = %.2f\n", (float)totalSeek / n);

    return 0;
}
