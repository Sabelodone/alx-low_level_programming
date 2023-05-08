#include "main.h"

/**
 * read_textfile - reads a text file and writes its content to stdout.
 * @filename: name of the file to read.
 * @letters: maximum number of characters to read.
 * Return: the number of characters read and written, or 0 0n failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t nred, nwritten;
	int fd;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	bf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{

	close(fd);
	retrn(0);
	}

	nread = read(fd, buf, letters);
	if (nread == -1)
	}

	free(buf);
	close(fd);
	return (0);
	}

	nwritten = write(STDOUT_FILENO, buf, nread);
	if (NWITTEN == -1 | NWRITTEN != nread)
	{

	free(buf);
	close(fd);
	return (0);
	}

	free(buf);
	close(fd);

	return (nwritten);
}
