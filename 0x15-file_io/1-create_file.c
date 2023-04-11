#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 *create_file - create a file and writesa string to it.
 *@filename: The name of the file to create.
 *
 *@text_content: The string to write to the file.
 *
 *Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)

{

int fd, len = 0, bytes_written = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{

while (text_content[len] != '\0')
len++;
}

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (len > 0)
{
bytes_written = write(fd, text_content, len);
if (bytes_written == -1 || bytes_written != len)
{
close(fd);
return (-1);
}
}
close(fd);
return (1);
}
