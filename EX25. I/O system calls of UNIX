#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char ch;
    struct stat s;

    fd = open("sample.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("File not found!\n");
        return 1;
    }

    lseek(fd, 5, SEEK_SET);
    read(fd, &ch, 1);

    printf("Character at position 5: %c\n", ch);

    stat("sample.txt", &s);
    printf("File Size: %ld bytes\n", s.st_size);

    close(fd);

    return 0;
}
