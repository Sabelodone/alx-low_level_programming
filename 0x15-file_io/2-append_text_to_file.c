#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text to end of file.
 * @filename: name of file
 * @text_content: text to append to file
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{

	int fd, lent = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	while (text_content[lent])
		lent++;

	write(fd, text_content, lent);

	close(fd);
	return (1);
}
