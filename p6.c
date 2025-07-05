#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the page size in bytes
#define PAGE_SIZE 4096 // 4KB

// Calculate the number of bits needed for the offset.
// log2(4096) = 12 bits
#define OFFSET_BITS 12

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex_logical_address>\n", argv[0]);
        return 1; // Indicate an error
    }

    unsigned long logical_address;
    char *endptr; // Pointer to the character after the number in argv[1]

    // Convert the hexadecimal string input to an unsigned long integer.
    logical_address = strtol(argv[1], &endptr, 16);

    // Basic error checking for strtol:
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: Invalid hexadecimal address '%s'. Please provide a valid hexadecimal number.\n", argv[1]);
        return 1;
    }

    // Calculate the Page Index:
    unsigned long page_index = logical_address >> OFFSET_BITS;

    // Calculate the Offset:
    unsigned long offset = logical_address & (PAGE_SIZE - 1);

    // Print the results in the specified hexadecimal format (uppercase, padded with zeros).
    printf("Logical Addr:0x%08lX - Page Index:0x%08lX - Offset:0x%08lX\n",
           logical_address, page_index, offset);

    return 0;
}