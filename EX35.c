#include <stdio.h>

int main()
{
    int n, indexBlock, i;

    printf("Enter Index Block Number: ");
    scanf("%d", &indexBlock);

    printf("Enter Number of File Blocks: ");
    scanf("%d", &n);

    int blocks[n];

    printf("Enter File Block Numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nIndexed File Allocation\n");
    printf("Index Block : %d\n\n", indexBlock);

    printf("Index Entry\tFile Block\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", i, blocks[i]);
    }

    return 0;
}
