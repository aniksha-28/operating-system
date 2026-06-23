#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int pageFaults = 0, flag, pos, farthest;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++)
    {
        flag = 0;

        /* Check if page is already present */
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        /* Page Fault */
        if(flag == 0)
        {
            pageFaults++;

            /* Find empty frame */
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = pages[i];
                    flag = 1;
                    break;
                }
            }

            /* Apply Optimal Replacement */
            if(flag == 0)
            {
                farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++)
                {
                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                            break;
                    }

                    if(k == n)
                    {
                        pos = j;
                        break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
