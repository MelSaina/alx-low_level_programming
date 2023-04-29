#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 *create_file  -  function that creates a file.
 *@filename:  name of the file to create and text_content is a NULL.
 *@text_content: the text to write to the file.
 *Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, written = 0;

	if (filename  ==  NULL)
	{
		return (-1);
	}
	else
	{
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1)
		{
			return (-1);
		}
		else
		{
			if (text_content != NULL)
			{
				while (text_content[len] != '\0')
				{
					len++;
				}
				written = write(fd, text_content, len);
				if (written == -1)
				{
					close(fd);
					return (-1);
				}
			}
		}
	}
	close(fd);
	return (1);

}
