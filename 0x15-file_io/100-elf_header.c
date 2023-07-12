#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>

void validate_elf(unsigned char *);
void print_info(unsigned char *, char *);

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int fd, r;
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: ./elf_info <file>\n");
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
	{
		dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	r = read(fd, header, sizeof(Elf64_Ehdr));
	if (r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	validate_elf(header->e_ident);

	print_info(header->e_ident, "Magic:");
	print_info(header->e_ident, "Class:");
	print_info(header->e_ident, "Data:");
	print_info(header->e_ident, "Version:");
	print_info(header->e_ident, "OS/ABI");
	printf("  ABI Version:\t\t\t%i\n", header->e_ident[EI_ABIVERSION]);
	print_info((unsigned char *)&(header->e_type), "Type:");
	print_info((unsigned char *)&(header->e_entry), "Entry:");

	free(header);

	if (close(fd))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(98);
	}

	return (0);
}

/**
 * validate_elf - helper function to check if input is a valid ELF file
 * @e_ident: pointer to char array
 */
void validate_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
	    e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not a valid ELF file\n");
		exit(98);
	}

	printf("ELF Header:\n");
}

/**
 * print_info - helper function to print ELF information
 * @data: pointer to data to be printed
 * @label: label for the data
 */
void print_info(unsigned char *data, char *label)
{
	printf("  %s ", label);

	switch (label[0])
	{
	case 'M':
		for (int i = 0; i < EI_NIDENT; i++)
			printf("%02x ", data[i]);
		printf("\n");
		break;
	case 'C':
		printf("ELF%d\n", data[EI_CLASS] == ELFCLASS32 ? 32 : 64);
		break;
	case 'D':
		printf("%s\n", data[EI_DATA] == ELFDATA2LSB ? "2's complement little endian" :
		             data[EI_DATA] == ELFDATA2MSB ? "2's complement big endian" :
		             "Unknown data format");
		break;
	case 'V':
		printf("%i\n", data[EI_VERSION]);
		break;
	case 'O':
		printf("%s\n", data[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		             data[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX" :
		             data[EI_OSABI] == ELFOSABI_NETBSD ? "netBSD" :
		             data[EI_OSABI] == ELFOSABI_LINUX ? "Linux" :
		             data[EI_OSABI] == ELFOSABI_SOLARIS ? "Sun Solaris" :
		             data[EI_OSABI] == ELFOSABI_IRIX ? "SGI Irix" :
		             data[EI_OSABI] == ELFOSABI_FREEBSD ? "FreeBSD" :
		             data[EI_OSABI] == ELFOSABI_TRU64 ? "Compaq TRU64 UNIX" :
		             data[EI_OSABI] == ELFOSABI_ARM ? "ARM architecture" :
		             data[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone (embedded) application" : "Unknown OS");
		break;
	case 'T':
		printf("%s\n", data[0] == ET_NONE ? "No file type" :
		             data[0] == ET_REL ? "Relocatable" :
		             data[0] == ET_EXEC ? "Executable file" :
		             data[0] == ET_DYN ? "Shared object file" :
		             data[0] == ET_CORE ? "Core file" :
		             "Unknown type");
		break;
	case 'E':
		if (sizeof(Elf64_Addr) == 4)
			printf("0x%x\n", *((Elf32_Addr *)data));
		else
			printf("0x%lx\n", *((Elf64_Addr *)data));
		break;
	default:
		printf("\n");
		break;
	}
}

