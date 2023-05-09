#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <elf.h>

void close_file(int fd);
void print_elf_entry(unsigned long int entry, unsigned char *header);
void print_elf_type(unsigned int type, unsigned char *header);
void print_elf_abi(unsigned char *header);
void print_elf_osabi(unsigned char *e_ident);
void print_elf_version(unsigned char *e_ident);
void print_elf_data(unsigned char *e_ident);
void print_elf_class(unsigned char *e_ident);
void print_elf_magic_numbers(unsigned char *e_ident);
void check_is_elf_file(unsigned char *e_ident);

/**
 * check_is_elf_file - Check if a file is an ELF file.
 * @e_ident: pointer to array containing magic numbers.
 * Description: file is not an ELF file - exit code 98.
 */
void check_is_elf_file(unsigned char *e_ident)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' &&
			e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_elf_magic_numbers - Print the magic numbers of ELF header.
 * @e_ident:pointer to an array containing  magic numbers.
 * Description: Magic numbers are separated by spaces.
 */

void print_elf_magic_numbers(unsigned char *e_ident)
{
	int i;
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * print_elf_class - Print class of an ELF header.
 * @e_ident: pointer to array containing the ELF class.
 */

void print_elf_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_elf_data - Prints the data encode of ELF header.
 * @e_ident:pointer to array containing  ELF class.
 */

void print_elf_data(unsigned char *e_ident)
{
	printf(" Data Encoding: ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_elf_version - version of an ELF header.
 * @e_ident:pointer to array containing ELF version.
 */

void print_elf_version(unsigned char *e_ident)
{
	printf(" ELF Version: %d",e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_elf_osabi - Print the OS/ABI of  ELF header.
 * @e_ident: an array with the ELF version.
 */

void print_elf_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_elf_abi - Prints ABI version of  ELF header.
 * @header: pointer to array containing ELF ABI version.
 */
void print_elf_abi(unsigned char *header)
{
	printf("  ABI Version:                       %d\n",header[EI_ABIVERSION]);
}

/**
 * print_elf_type - Prints the type of an ELF header.
 * @type: The ELF type.
 * @header: A pointer to an array containing the ELF class.
 */

void print_elf_type(unsigned int type, unsigned char *header)
{
	if (header[EI_DATA] == ELFDATA2MSB)
		type >>= 8;
	printf("  Type:                              ");
	switch (type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type);
	}
}

/**
 * print_elf_entry - Prints the entry point of an ELF header.
 * @entry: The address of the ELF entry point.
 * @header: A pointer to an array containing the ELF class.
 */

void print_elf_entry(unsigned long int entry, unsigned char *header)
{
	printf("  Entry point address:               ");
	if (header[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}
	if (header[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)entry);
	}
	else
	{
		printf("%#lx\n", entry);
	}
}

/**
 * close_file - Closes a file.
 * @fd: file descriptor .
 * Description: If the file cannot be closed - exit code 98.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * print_elf_info - Displays the information contained in the ELF header
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_status;
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_status = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_status == -1)
	{
		free(header);
		close_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_is_elf_file(header->e_ident);
	print_elf_magic_numbers((unsigned char *)"ELF Header:\n");
	print_elf_class(header->e_ident);
	print_elf_data(header->e_ident);
	print_elf_version(header->e_ident);
	print_elf_osabi(header->e_ident);
	print_elf_abi(header->e_ident);
	print_elf_type(header->e_type, header->e_ident);
	print_elf_entry(header->e_entry, header->e_ident);

	free(header);
	close_file(file_descriptor);
	return (0);
}
