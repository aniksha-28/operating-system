#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    printf("Thread Created Successfully\n");
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, display, NULL);

    pthread_join(tid, NULL);

    return 0;
}
