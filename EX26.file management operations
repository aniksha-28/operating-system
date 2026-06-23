#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[50], data[200], ch;
    int choice;

    while(1)
    {
        printf("\n----- FILE MANAGEMENT OPERATIONS -----\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Append to File\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");
                if(fp == NULL)
                    printf("File cannot be created!\n");
                else
                {
                    printf("File created successfully.\n");
                    fclose(fp);
                }
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");
                if(fp == NULL)
                {
                    printf("File cannot be opened!\n");
                }
                else
                {
                    printf("Enter data: ");
                    getchar(); // clear buffer
                    fgets(data, sizeof(data), stdin);

                    fputs(data, fp);
                    fclose(fp);
                    printf("Data written successfully.\n");
                }
                break;

            case 3:
                printf("Enter file name: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");
                if(fp == NULL)
                {
                    printf("File not found!\n");
                }
                else
                {
                    printf("\nFile Contents:\n");
                    while((ch = fgetc(fp)) != EOF)
                    {
                        printf("%c", ch);
                    }
                    fclose(fp);
                }
                break;

            case 4:
                printf("Enter file name: ");
                scanf("%s", filename);

                fp = fopen(filename, "a");
                if(fp == NULL)
                {
                    printf("File cannot be opened!\n");
                }
                else
                {
                    printf("Enter data to append: ");
                    getchar();
                    fgets(data, sizeof(data), stdin);

                    fputs(data, fp);
                    fclose(fp);
                    printf("Data appended successfully.\n");
                }
                break;

            case 5:
                printf("Enter file name: ");
                scanf("%s", filename);

                if(remove(filename) == 0)
                    printf("File deleted successfully.\n");
                else
                    printf("Unable to delete file.\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
