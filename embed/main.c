#include <stdio.h>
#include <stdint.h>

#define WAV_FILE_NAME "sine.wav"

/* #embed is C23 directive which includes binary data from external file into a source code */
static const unsigned char wav_data[] = {
    #embed WAV_FILE_NAME
};

// .wav file header structure
typedef struct {
    char riff[4];
    uint32_t size;
    char wave[4];
    char fmt_chunk_id[4];
    uint32_t fmt_chunk_size;
    uint16_t format;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char data_chunk_id[4];
    uint32_t data_size;
} wav_header_t;

int main(void) {
    const wav_header_t* hdr = (const wav_header_t*)wav_data;

    printf("Header type size: %zu, %s file size: %zu\n\n", sizeof(wav_header_t), WAV_FILE_NAME, sizeof(wav_data));

    printf("%s header content:\n", WAV_FILE_NAME);
    printf("Riff:            %c%c%c%c\n", hdr->riff[0], hdr->riff[1], hdr->riff[2], hdr->riff[3]);
    printf("Size:            %u bytes\n", hdr->size);
    printf("Wave:            %c%c%c%c\n", hdr->wave[0], hdr->wave[1], hdr->wave[2], hdr->wave[3]);
    printf("Fmt chunk id:    %c%c%c%c\n", hdr->fmt_chunk_id[0], hdr->fmt_chunk_id[1], hdr->fmt_chunk_id[2], hdr->fmt_chunk_id[3]);
    printf("Format:          %u\n", hdr->format);
    printf("Channels:        %d\n", hdr->channels);
    printf("Sample rate:     %u Hz\n", hdr->sample_rate);
    printf("Byte rate:       %d\n", hdr->byte_rate);
    printf("Block align:     %d\n", hdr->block_align);
    printf("Bits per sample: %d\n", hdr->bits_per_sample);
    printf("Data chunk id:   %c%c%c%c\n", hdr->data_chunk_id[0], hdr->data_chunk_id[1], hdr->data_chunk_id[2], hdr->data_chunk_id[3]);
    printf("Data size:       %u bytes\n\n", hdr->data_size);

    const unsigned char *data = wav_data + sizeof(wav_header_t);
    printf("Data (first 8 bytes): 0x%02x%02x%02x%02x...\n", data[0], data[1], data[2], data[3]);

    return 0;
}
