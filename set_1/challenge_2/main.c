/*
 * main.c
 *
 * Harness to test XOR
 *
 * Author: Jeffrey Picard
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint8_t *xor(uint8_t *, uint8_t *, uint32_t);
uint8_t *hex_decode(char *s, uint32_t n);

int
main(int argc, char **argv)
{
	uint8_t buf_0[] = {0xf0,0,1,0,0xf0};
	uint8_t buf_1[] = {0x00,1,0,1,0x0f};
	uint8_t *r;
	uint32_t i;
	uint32_t l, m, n;

	char *s0 = "1c0111001f010100061a024b53535009181c";
	char *s1 = "686974207468652062756c6c277320657965";
	char *s2 = "c";

	uint8_t *buf0;
	uint8_t *buf1;
	uint8_t *buf2;

	fprintf(stderr,"##### hex decode tests #####\n");

	buf0 = hex_decode(s0, strlen(s0));
	l = strlen(s0) % 2 ? strlen(s0) / 2 + 1 : strlen(s0) / 2;

	fprintf(stderr, "%s\n", s0);
	for (i = 0; i < l; i++)
		fprintf(stderr, "%02x", buf0[i]);
	fprintf(stderr, "\n");

	buf1 = hex_decode(s1, strlen(s1));
	m = strlen(s1) % 2 ? strlen(s1) / 2 + 1 : strlen(s1) / 2;

	fprintf(stderr, "%s\n", s1);
	for (i = 0; i < m; i++)
		fprintf(stderr, "%02x", buf1[i]);
	fprintf(stderr, "\n");
	
	buf2 = hex_decode(s2, strlen(s2));
	n = strlen(s2) % 2 ? strlen(s2) / 2 + 1 : strlen(s2) / 2;

	fprintf(stderr, "%s\n", s2);
	for (i = 0; i < n; i++)
		fprintf(stderr, "%02x", buf2[i]);
	fprintf(stderr, "\n");

	fprintf(stderr,"##### xor tests #####\n");

	r = xor(buf_0, buf_1, sizeof buf_0);
	for (i = 0; i < sizeof buf_0; i++)
		fprintf(stderr, "%02x\n", r[i]);

	fprintf(stderr, "%s\n", s0);
	fprintf(stderr, "%s\n", s1);
	r = xor(buf0, buf1, l);
	for (i = 0; i < l; i++)
		fprintf(stderr, "%02x", r[i]);
	fprintf(stderr, "\n");

	return 0;
}
