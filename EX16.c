#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp;
    int choice, pos;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
        fp = fopen("employee.dat", "wb+");

    do
    {
        printf("\n1. Add Employee\n");
        printf("2. Display Employee by Record Number\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Employee ID: ");
            scanf("%d", &emp.id);

            printf("Enter Employee Name: ");
            scanf("%s", emp.name);

            printf("Enter Salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, (emp.id - 1) * sizeof(struct Employee), SEEK_SET);
            fwrite(&emp, sizeof(struct Employee), 1, fp);

            printf("Record Stored Successfully.\n");
            break;

        case 2:
            printf("Enter Employee ID to Search: ");
            scanf("%d", &pos);

            fseek(fp, (pos - 1) * sizeof(struct Employee), SEEK_SET);

            fread(&emp, sizeof(struct Employee), 1, fp);

            if (emp.id != 0)
            {
                printf("\nEmployee Details\n");
                printf("ID     : %d\n", emp.id);
                printf("Name   : %s\n", emp.name);
                printf("Salary : %.2f\n", emp.salary);
            }
            else
            {
                printf("Record not found.\n");
            }
            break;

        case 3:
            fclose(fp);
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}
