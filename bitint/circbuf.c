#include <stdio.h>

constexpr unsigned char circ_buf_bit_width = 3;
constexpr unsigned char circ_buf_len = 1 << circ_buf_bit_width;
unsigned char circ_buf[circ_buf_len];

/* _BitInt is C23 type which allows to define integer of given
    bit-size. In this case it is 3-bit long variable so it can
    have values in a range [0...7] */
unsigned _BitInt(circ_buf_bit_width) circ_buf_idx = 0u;
unsigned _BitInt(160) longlong_bitint = 0u;

int main(void)
{
    printf("circ_buf_len = %u\n\n", circ_buf_len);

    for (int i = 0; i < circ_buf_len * 2; i++)
    {
        circ_buf[circ_buf_idx] = i;
        printf("circ_buf[%u]: %d\n", circ_buf_idx, circ_buf[circ_buf_idx]);

        /* circ_buf_idx is defined as bit-precise integer, so it wraps automatically after reaching 7 */
        circ_buf_idx += 1;
    }

    return 0;
}