#include <stdio.h>
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

    /* Sort the requests */
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

    /* Find position of first request >= head */
    int pos = n;
    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d", head);

    /* Service requests to the right */
    for(i = pos; i < n; i++)
    {
        totalSeek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    /* Move to end of disk */
    totalSeek += abs((size - 1) - head);
    head = size - 1;
    printf(" -> %d", head);

    /* Jump to beginning */
    totalSeek += (size - 1);
    head = 0;
    printf(" -> %d", head);

    /* Service remaining requests */
    for(i = 0; i < pos; i++)
    {
        totalSeek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", totalSeek);
    printf("\nAverage Seek Time = %.2f\n",
           (float)totalSeek / n);

    return 0;
}
