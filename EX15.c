#include <stdio.h>

int main()
{
    int users, files, i, j;
    char dirname[10][20];
    char filename[10][10][20];

    printf("Enter number of directories (users): ");
    scanf("%d", &users);

    for(i = 0; i < users; i++)
    {
        printf("\nEnter directory name: ");
        scanf("%s", dirname[i]);

        printf("Enter number of files in %s: ", dirname[i]);
        scanf("%d", &files);

        for(j = 0; j < files; j++)
        {
            printf("Enter file %d: ", j + 1);
            scanf("%s", filename[i][j]);
        }
    }

    printf("\n\nTWO LEVEL DIRECTORY STRUCTURE\n");

    for(i = 0; i < users; i++)
    {
        printf("\nDirectory: %s\n", dirname[i]);

        for(j = 0; filename[i][j][0] != '\0'; j++)
        {
            printf("   %s\n", filename[i][j]);
        }
    }

    return 0;
}
