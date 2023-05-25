#include "main.h"
#include <stdio.h>

/**
 * main - coppies content of one file to another
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 on success, or an erro code on failure.
 */

int main(int ac, char **av)
{

	int fd_src, fd_dest;
	char buffer[1024];

	if (ac != 3)
	{
	  printf("Usage: ./program_name source_file destination_file\n");
		return (1);

	fd_src = open(av[1], O_RDONLY);
	if (fd_src == -1)
	{
	  printf("Failed to open the source file.\n");
		return (1);
	}

	fd_dest = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_dest == -1)
	{

	  printf("Failed to destination file.\n");
	  close(fd_src);
		return (1);
	}
}

	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0)

	{

	bytes_written = write(fd_dest, buffer, bytes_read);
	if (bytes_written != bytes_read)
	{

	  printf("Failed to write to the destination file.\n");
		close(fd_src);
		close(fd_dest);
		return (1);

	}

}

		close(fd_src);
		close(fd_dest);

			return (0);

}
