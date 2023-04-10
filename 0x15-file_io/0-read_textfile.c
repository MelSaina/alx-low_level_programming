#include "main.h"
#include <fcntl.h>
/**
 *read_textfile - reads a text file and prints it to POSIX standard output.
 *@filename:  A pointer to the name of the file.
 *@letters: The number of letters that  should read and print
 *Return: file can not be opened or read 0
 *	filename is NULL return 0
 *	fails or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename  ==  NULL)
	{
	return (0);
	}
	else
	{
	int fd =  open(filename, O_RDONLY);
		if (fd  ==  -1)
		{
		return (0);
		}
		else
		{
		char buffer[1024];
		ssize_t n, total = 0;

			while (letters > 0 && (n = read(fd, buffer, sizeof(buffer))) > 0)
			{
				if (n > (ssize_t) letters)
				{
				n = letters;
				}
				else
				{
				ssize_t written = write(STDOUT_FILENO, buffer, n);
					if (written == -1 || written != n)
					{
					close(fd);
					return (0);
					}
					else
					{
					letters -= n;
					total += n;
					}
				}
			}
			close(fd);
			return (total);
		}
	}
}
