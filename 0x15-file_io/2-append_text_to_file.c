#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 *append_text_to_file - a function that appends text at the end of a file.
 *@filename: name of the file
 *@text_content: the NULL terminated string to add at the end of the file.
 *Return: 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
int f, b_w  =  0, len  =  0;

	if (filename  ==  NULL)
	{
		return (-1);
	}
	else
	{
		if (text_content  ==  NULL)
		{
			return (1);
		}
		else
		{
			f = open(filename, O_WRONLY | O_APPEND);

			if (f  ==  -1)
			{
				return (-1);
			}
			else
			{
				while (*(text_content + len))
				{
					len++;
				}
				b_w  =  write(f, text_content, len);
				close(f);

				if (b_w != len)
				{
					return (-1);
				}
			}
		}
	}
	return (1);
}
