#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

/**
 * elf_header - prints the ELF header of a given file
 * @filename: the name of the file to read the ELF header from
 *
 * Return: 0 on success, -1 on error
 */
int elf_header(char *filename)
{
	int fd, i;
	char buf[BUF_SIZE];
	Elf64_Ehdr *header64;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		return (-1);
	}

	if (read(fd, buf, sizeof(Elf64_Ehdr)) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		close(fd);
		return (-1);
	}

	header64 = (Elf64_Ehdr *)buf;

	/* Check if ELF file */
	if (header64->e_ident[EI_MAG0] != ELFMAG0 ||
		header64->e_ident[EI_MAG1] != ELFMAG1 ||
		header64->e_ident[EI_MAG2] != ELFMAG2 ||
		header64->e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: File %s is not an ELF file\n", filename);
		close(fd);
		return (98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header64->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             ");
	switch (header64->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("Invalid class\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", header64->e_ident[EI_CLASS]);
		break;
	}

	printf("  Data:                              ");
	switch (header64->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("Invalid data encoding\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", header64->e_ident[EI_DATA]);
		break;
	}

	printf("  Version:                           %d (current)\n", header64->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header64->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("HP-UX ABI\n");
		break;
	case ELFOSABI_NETBSD:
		printf("NetBSD ABI\n");
		break;
	case ELFOSABI_LINUX:
		printf("Linux ABI\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("Solaris ABI\n");
		break;
	default:
		printf("<unknown: %x>\n", header64->e_ident[EI_OSABI]);
		break;
	}
	return (0);
}
