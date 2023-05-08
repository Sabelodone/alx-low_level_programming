#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - creates a new file and writes text to it.
 * @filename: name of the file to create.
 * @text_content: text to write to the file
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{

	int fd = -1;
	ssize_t w;
	size_t size;

	if (!filename)
		return (-1);

	fd = open(filename,  O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (text_content)
	{

	for (size = 0; *(text_content + size); size++)
	;

	w = write(fd, text_content, size);
	if (w == -1)
	{
		close(fd);
		return (-10);

		}
	}

	close(fd);
	return (1);
}
