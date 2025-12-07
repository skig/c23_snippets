#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* In C23 _BitInt(N) is N-bit integer */
unsigned _BitInt(256) int_256_bits_1 = (unsigned _BitInt(256))1 << 255;
unsigned _BitInt(256) int_256_bits_2 = (unsigned _BitInt(256))1 << 130;

void print_bitint_bytes(unsigned _BitInt(256) value) {
    unsigned char bytes[sizeof(int_256_bits_2)];

    memcpy(bytes, &value, sizeof(value));
    for (int i = 0; i < sizeof(bytes); i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
}

int main(void)
{
    printf("sizeof(unsigned _BitInt(256)): %zu\n\n", sizeof(unsigned _BitInt(256)));

    unsigned _BitInt(256) int_256_bits_3 = int_256_bits_1 ^ ~int_256_bits_2;

    printf("int_256_bits_1: ");
    print_bitint_bytes(int_256_bits_1);
    printf("int_256_bits_2: ");
    print_bitint_bytes(int_256_bits_2);
    printf("int_256_bits_3: ");
    print_bitint_bytes(int_256_bits_3);

    return 0;
}