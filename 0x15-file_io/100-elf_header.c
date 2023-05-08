#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

#define EI_NIDENT 16
#define ELFCLASSNONE 0
#define ELFCLASS32 1
#define ELFCLASS64 2
#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2
#define EV_CURRENT 1

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

void print_error(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header(char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        print_error("could not open file");
    }

    char buf[BUFSIZ];
    ssize_t n = read(fd, buf, BUFSIZ);
    if (n < 0) {
        print_error("could not read ELF header");
    }

    if (n < sizeof(Elf64_Ehdr)) {
        print_error("file too small");
    }

    Elf64_Ehdr *header = (Elf64_Ehdr *) buf;

    if (header->e_ident[0] != 0x7f || header->e_ident[1] != 'E' ||
        header->e_ident[2] != 'L' || header->e_ident[3] != 'F') {
        print_error("not an ELF file");
    }

    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                             ");
    switch (header->e_ident[4]) {
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
            printf("invalid\n");
            break;
    }

    printf("Data:                              ");
    switch (header->e_ident[5]) {
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
            printf("invalid\n");
            break;
    }

    printf("Version:                           %u\n", header->e_ident[6]);

    printf("OS/ABI:                            ");
    switch (header->e_ident[7]) {
    case 0:
        printf("System V\n");
        break;
    case 1:
        printf("HP-UX\n");
        break;
    case 2:
        printf("NetBSD\n");
        break;
    case 3:
        printf("Linux\n");
        break;
    case 6:
        printf("Sun Solaris\n");
        break;
    case 7:
        printf("AIX\n");
        break;
    case 8:
        printf("IRIX\n");
        break;
}
}
