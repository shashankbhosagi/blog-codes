#include <stdio.h>
#include <stdint.h>

// Function to print the binary representation of a value
void print_binary(uint64_t num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%c", (num & (1ULL << i)) ? '1' : '0');
        if (i % 8 == 0) printf(" "); // Add space every 8 bits for readability
    }
    printf("\n");
}

#define PRINT_SHIFT(type, value) \
    do { \
        printf("\nData Type: %s\n", #type); \
        printf("Original Value: %lld\n", (long long)(value)); \
        printf("Original Binary: "); \
        print_binary((uint64_t)(value), sizeof(type) * 8); \
        printf("Right Shift (>> 1): %lld | ", (long long)((value) >> 1)); \
        print_binary((uint64_t)((value) >> 1), sizeof(type) * 8); \
        printf("Left Shift (<< 1): %lld | ", (long long)((value) << 1)); \
        print_binary((uint64_t)((value) << 1), sizeof(type) * 8); \
    } while (0)

int main() {
    printf("\n=== Bit Shift Demo ===\n");

    // Signed types
    PRINT_SHIFT(signed char, -10);
    PRINT_SHIFT(signed short, -1000);
    PRINT_SHIFT(signed int, -100000);
    PRINT_SHIFT(signed long, -1000000000L);
    PRINT_SHIFT(signed long long, -9000000000000000000LL);

    // Unsigned types
    PRINT_SHIFT(unsigned char, 100);
    PRINT_SHIFT(unsigned short, 10000);
    PRINT_SHIFT(unsigned int, 3000000000U);
    PRINT_SHIFT(unsigned long, 4000000000000UL);
    PRINT_SHIFT(unsigned long long, 18000000000000000000ULL);

    // Enum (treated as int)
    enum TestEnum { A = 5 };
    PRINT_SHIFT(enum TestEnum, A);

    // _Bool (bit shift on bool is allowed but not meaningful)
    PRINT_SHIFT(_Bool, 1);

    return 0;
}
