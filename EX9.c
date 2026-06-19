#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    char *str;

    // Create shared memory
    shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

    // Attach shared memory
    str = (char *)shmat(shmid, NULL, 0);

    printf("Enter a message: ");
    scanf("%s", str);

    printf("Data written to shared memory: %s\n", str);

    return 0;
}
