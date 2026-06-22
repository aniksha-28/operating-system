#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void producer()
{
    mutex--;
    empty--;
    full++;

    x++;
    printf("Producer produces item %d\n", x);

    mutex++;
}

void consumer()
{
    mutex--;
    full--;
    empty++;

    printf("Consumer consumes item %d\n", x);
    x--;

    mutex++;
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is Full!");
            break;

        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is Empty!");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid Choice!");
        }
    }

    return 0;
}
