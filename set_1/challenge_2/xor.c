/*
 * xor.c
 *
 * XOR two fixed length buffers
 *
 * Author: Jeffrey Picard
 */

#include <stdint.h>
#include <stdlib.h>

uint8_t *
xor(uint8_t *data_0, uint8_t *data_1, uint32_t len)
{
	uint32_t i;	
	uint8_t *out_buf = malloc(len);

	if (!out_buf) return 0;
	
	for (i = 0; i < len; i++)
		out_buf[i] = data_0[i] ^ data_1[i];

	return out_buf;
}
