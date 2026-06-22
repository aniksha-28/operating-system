#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    /* Create and open a file */
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if(fd < 0)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    /* Write to file */
    write(fd, "Hello UNIX System Calls", 23);

    /* Move file pointer to beginning */
    lseek(fd, 0, SEEK_SET);

    /* Read from file */
    read(fd, buffer, 23);
    buffer[23] = '\0';

    printf("Data read from file: %s\n", buffer);

    /* Close file */
    close(fd);

    return 0;
}
