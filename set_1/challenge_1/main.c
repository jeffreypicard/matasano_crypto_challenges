/*
 * main.c
 *
 * Harness for crypto challenge 1.
 *
 * Author: Jeffrey Picard
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
char *base64_encode(char *data, uint32_t in_len, uint32_t *out_len);

int
main(int argc, char *argv[])
{
	int x = 0xffffffff;
	char *a = "Man";
	char *b = "Ma";
	char *c = "M";
	char *words =
		"Man is distinguished, not only by his reason, but by this singular passion from"
		"other animals, which is a lust of the mind, that by a perseverance of delight"
		"in the continued and indefatigable generation of knowledge, exceeds the short"
		"vehemence of any carnal pleasure.";
	uint32_t len;
	char *s;

	s = base64_encode((char *)&x, 4, &len);
	printf("%s\n", s);
	s = base64_encode(a, 3, &len);
	printf("%s\n", s);
	s = base64_encode(b, 2, &len);
	printf("%s\n", s);
	s = base64_encode(c, 1, &len);
	printf("%s\n", s);
	s = base64_encode(words, strlen(words), &len);
	printf("%s\n", s);

	return 0;
}
