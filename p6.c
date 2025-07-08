#include <stdio.h>
#include <stdlib.h> 

// Defines the size of a memory page in bytes
#define PAGE_SIZE 4096 // A common page size, 4 kilobytes

// Defines the number of bits used for the offset within a page
#define OFFSET_BITS 12 // 2^12 = 4096, so 12 bits cover a 4KB page

int main(int argc, const char *argv[]) { // Main function, takes command-line arguments
    // Checks if the correct number of arguments was provided
    if (argc != 2) { // Expects program name and one hexadecimal address
        fprintf(stderr, "Usage: %s <hex_logical_address>\n", argv[0]); // Prints usage message to error stream
        return 1; // Exits with an error code
    }

    unsigned long logical_address; // Declares a variable to hold the numerical logical address
    char *endptr; // Declares a pointer to check where string conversion stops

    // Converts the input string (hexadecimal) to an unsigned long integer
    logical_address = strtol(argv[1], &endptr, 16); // Uses base 16 for hexadecimal conversion

    // Checks for errors during the string to number conversion
    if (*endptr != '\0' || endptr == argv[1]) { // If conversion stopped prematurely or no digits found
        fprintf(stderr, "Error: Invalid hexadecimal address '%s'. Please provide a valid hexadecimal number.\n", argv[1]); // Prints an error message
        return 1; // Exits with an error code
    }

    // Calculates the page index from the logical address
    unsigned long page_index = logical_address >> OFFSET_BITS; // Shifts right to get the higher bits (page index)

    // Calculates the offset within the page
    unsigned long offset = logical_address & (PAGE_SIZE - 1); // Uses bitwise AND to get the lower bits (offset)

    // Prints the original logical address, calculated page index, and offset
    printf("Logical Addr:0x%08lX - Page Index:0x%08lX - Offset:0x%08lX\n", // Formats output as uppercase hexadecimal with leading zeros
           logical_address, page_index, offset); // Passes the calculated values to printf

    return 0; // Exits successfully
}