#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50], word[50], line[200];
    int line_no = 0, found = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("\nMatching lines:\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line_no++;

        if (strstr(line, word) != NULL)
        {
            printf("Line %d: %s", line_no, line);
            found = 1;
        }
    }

    if (!found)
        printf("Word not found in the file.\n");

    fclose(fp);

    return 0;
}
