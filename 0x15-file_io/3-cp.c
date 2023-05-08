#include <fcntl.h>
#include <errno.h>
#include "main.h"
#define BUFFER_SIZE 1024

int main (int argc, char *argv[])
{
	int f_from, f_to, num_rd, no_w;
	char buffer[BUFFER_SIZE];

	if (argc  !=  3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	else
	{
		f_from  =  open(argv[1], O_RDONLY);
		if (f_from  ==  -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		else
		{
			f_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
			if (f_to  ==  -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99);
			}
			else
			{
				while ((num_rd  = read(f_from, buffer, BUFFER_SIZE)) > 0)
				{
					no_w  = write(f_to, buffer, num_rd);
					if (no_w  ==  -1)
					{
						dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
						exit(99);
					}
					else
					{
						if (no_w  != num_rd)
						{
							dprintf(STDERR_FILENO, "Error: Short write to %s\n", argv[2]);
							exit(99);
						}
					}
				}
				if (num_rd  ==  -1)
				{
					dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
					exit(98);
				}
				else
				{
					if (close(f_from)  ==  -1)
					{
						dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_from);
						exit(100);
					}
					else
					{
						if (close(f_to)  ==  -1)
						{
							dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_to);
							exit(100);
						}
					}
				}
			}
		}
	}
	return (0);
}
