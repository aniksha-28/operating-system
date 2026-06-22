#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt;
pthread_mutex_t mutex;

int readcount = 0;
int data = 10;

void *reader(void *arg)
{
    int id = *(int *)arg;

    pthread_mutex_lock(&mutex);
    readcount++;

    if (readcount == 1)
        sem_wait(&wrt);

    pthread_mutex_unlock(&mutex);

    printf("Reader %d reads data = %d\n", id, data);

    pthread_mutex_lock(&mutex);
    readcount--;

    if (readcount == 0)
        sem_post(&wrt);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&wrt);

    data = data + 5;
    printf("Writer %d writes data = %d\n", id, data);

    sem_post(&wrt);

    return NULL;
}

int main()
{
    pthread_t r1, r2, w1;
    int id1 = 1, id2 = 2, id3 = 1;

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&w1, NULL, writer, &id3);
    pthread_create(&r2, NULL, reader, &id2);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);

    return 0;
}
