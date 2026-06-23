#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produces item %d\n", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

int main()
{
    int n, ch;

    printf("1. Producer\n");
    printf("2. Consumer\n");
    printf("3. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is Full!\n");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is Empty!\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
