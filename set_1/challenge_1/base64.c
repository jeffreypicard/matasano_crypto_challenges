/*
 * base64.c
 *
 * base64 encode and decode functions.
 *
 * Author: Jeffrey Picard
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static const char table[] = { 
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
	'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', '+', '/'
};

char *
bytes_to_string(uint8_t *data, uint32_t len)
{
	uint32_t i;
	char *s = calloc(len + 1, sizeof(char));
	if (!s) return 0;

	for (i = 0; i < len; i++) {
		s[i] = table[data[i]];
	}

	return s;
}

/*
 * base64_encode
 *
 * encode data (as raw bytes) into base64 (again raw bytes, *not* string).
 * 
 */
uint8_t *
base64_encode(uint8_t *data, uint32_t in_len, uint32_t *out_len)
{
	uint32_t i;
	uint32_t j;

	/* if in_len % 3 != 0, we need another 4 bytes */
	*out_len = 4 * ((in_len + 2) / 3);

	uint8_t *out_buf = calloc(*out_len + 1, sizeof(char));
	if (!out_buf) return 0;

	j = 0;
	for	(i = 0; i < *out_len; i += 4) {
		uint32_t buf;

		/* Check to see if we're near the end and need one or two equal signs
		 * FIXME: This could probably be done once before the for loop */
		uint8_t one_eq = j + 1 < in_len ? 0 : 1;
		uint8_t two_eq = j + 2 < in_len ? 0 : 1;

		uint8_t octet_0 = data[j++];
		uint8_t octet_1 = one_eq ? 0x00 : data[j++];
		uint8_t octet_2 = two_eq ? 0x00 : data[j++];
		buf = octet_0 << 16 | octet_1 << 8 | octet_2;

		uint8_t sextet_0 = buf >> 18;
		uint8_t sextet_1 = (buf >> 12) & 0x3F;
		uint8_t sextet_2 = (buf >> 6) & 0x3F;
		uint8_t sextet_3 = buf & 0x3F;
		
		out_buf[i] = sextet_0;
		out_buf[i+1] = sextet_1;
		out_buf[i+2] = one_eq ? 0xff : sextet_2;
		out_buf[i+3] = two_eq ? 0xff : sextet_3;

		if (one_eq) *out_len = *out_len - 1;
		if (two_eq) *out_len = *out_len - 1;
	}

	return out_buf;
}
