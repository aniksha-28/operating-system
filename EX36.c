#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    int block[n];

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("\nLinked Allocation File Structure\n");
    printf("First Block : %d\n", block[0]);
    printf("Last Block  : %d\n\n", block[n - 1]);

    printf("Block\tNext Block\n");

    for(i = 0; i < n - 1; i++)
    {
        printf("%d\t%d\n", block[i], block[i + 1]);
    }

    printf("%d\tNULL\n", block[n - 1]);

    printf("\nFile Traversal:\n");

    for(i = 0; i < n - 1; i++)
    {
        printf("%d -> ", block[i]);
    }

    printf("%d -> NULL\n", block[n - 1]);

    return 0;
}
