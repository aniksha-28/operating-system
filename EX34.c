#include <stdio.h>

int main()
{
    int n, start, i;

    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    int block[n], next[n];

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("Enter starting block index (0 to %d): ", n - 1);
    scanf("%d", &start);

    /* Creating links */
    for(i = 0; i < n - 1; i++)
    {
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    printf("\nLinked File Allocation:\n");
    printf("Block\tNext Block\n");

    for(i = 0; i < n; i++)
    {
        if(next[i] == -1)
            printf("%d\tNULL\n", block[i]);
        else
            printf("%d\t%d\n", block[i], block[next[i]]);
    }

    printf("\nFile Traversal:\n");

    i = start;
    while(i != -1)
    {
        printf("%d -> ", block[i]);
        i = next[i];
    }

    printf("NULL\n");

    return 0;
}
