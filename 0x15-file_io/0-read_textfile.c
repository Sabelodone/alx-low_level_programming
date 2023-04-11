#include <stdlib.h>
#include "main.h"
/**
*print_file - Reads a file and prints its contents to the POSIX stdout.
*@filename: the name of the file to read.
*@letters: the maximum number of bytes to read and print.
*
*Return: the maximum number of bytesprinted, or 0 on failure.
*/

ssize_t print_file(const char *filename, size_t letters)

{

if (filename == NULL)
return (0);

int fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

char *buffer = malloc(letters * sizeof(char));
if (buffer == NULL)

{
close(fd);
return (0);
}

ssize_t bytes_read = read(fd, buffer, letters);
if (bytes_read == -1)
{

free(buffer);
close(fd);
return (0);

}

ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{

free(buffer);
close(fd);
return (0);
}

free(buffer);
close(fd);
return (bytes_written);
}
