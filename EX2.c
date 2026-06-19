#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, dest;
    char buffer[100];
    int bytes;

    // Open source file in read mode
    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Error opening source file\n");
        return 1;
    }

    // Create/Open destination file in write mode
    dest = open("destination.txt",
                O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest < 0)
    {
        printf("Error opening destination file\n");
        close(source);
        return 1;
    }

    // Read from source and write to destination
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(dest, buffer, bytes);
    }

    printf("File copied successfully.\n");

    // Close files
    close(source);
    close(dest);

    return 0;
}
