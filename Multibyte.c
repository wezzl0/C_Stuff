
#include <stdio.h>

int main(void) {

	unsigned char ip[4] = {1, 1, 0, 0};
											// (For little endian)
	unsigned int ipAsInt = * (int *) &ip;	// Multi-byte values are stored with the least-significant bytes first.
											// For example, if we were to cast the array 'ip' as an integer:
	printf("%u", ipAsInt);					// {Bits 7-0, Bits 15-8, Bits 23-16, Bits 31-24}
											// {0000 0001, 0000 0001, 0000 0000, 0000 0000} read as integer '257'.
	return 0;
}
