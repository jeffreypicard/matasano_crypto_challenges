/*
 * hex_decode.c
 * 
 * Decode a char* of hex into it's byte representation
 *
 * Author: Jeffrey Picard
 */

#include <stdlib.h>
#include <assert.h>

uint8_t
char_to_nibble(char c)
{
	switch(c) {
		case '0':
			return 0x0;
		case '1':
			return 0x1;
		case '2':
			return 0x2;
		case '3':
			return 0x3;
		case '4':
			return 0x4;
		case '5':
			return 0x5;
		case '6':
			return 0x6;
		case '7':
			return 0x7;
		case '8':
			return 0x8;
		case '9':
			return 0x9;
		case 'a':
		case 'A':
			return 0xA;
		case 'b':
		case 'B':
			return 0xB;
		case 'c':
		case 'C':
			return 0xC;
		case 'd':
		case 'D':
			return 0xD;
		case 'e':
		case 'E':
			return 0xE;
		case 'f':
		case 'F':
			return 0xF;
		default:
			return -1;
	};
}

uint8_t *
hex_decode(char *s, uint32_t n) 
{
	uint32_t i, j;
	uint32_t m;
	uint8_t *buf;
	uint8_t odd_len = n % 2;

	buf = odd_len ? malloc(n / 2 + 1) : malloc(n / 2);
	assert(buf);

	m = odd_len ? n : n - 1;

	for (i = 0, j = 0; i < m; i += 2, j++)
		buf[j] = char_to_nibble(s[i]) << 4 | char_to_nibble(s[i+1]);

	buf[j-1] = odd_len ? char_to_nibble(s[n-1]) << 4 : buf[j-1];

	return buf;
}
