#include <stdio.h>

int main()
{
    int i;
    int state[5] = {0, 0, 0, 0, 0}; // 0 = Thinking, 1 = Eating

    printf("Dining Philosophers Problem Simulation\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("Philosopher %d is Thinking\n", i + 1);
    }

    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("Philosopher %d picks up left fork\n", i + 1);
        printf("Philosopher %d picks up right fork\n", i + 1);

        state[i] = 1;

        printf("Philosopher %d is Eating\n", i + 1);

        printf("Philosopher %d puts down left fork\n", i + 1);
        printf("Philosopher %d puts down right fork\n", i + 1);

        state[i] = 0;

        printf("Philosopher %d is Thinking\n\n", i + 1);
    }

    return 0;
}
