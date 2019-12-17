#include<stdio.h>
// Nicholas Fay
// 01/18/19
// part 2-2

unsigned int extract(unsigned int x, int i)
{
	// determines how many bits are needed to be shifted.
	unsigned int shift = (i << 3);
	//printf("The shift is: %d\n", shift);
	// shifts 0xff by i^3  bits to get the ones in the correct location to mask the values out that we want.
	unsigned int mask = 0xFF << shift;
	//printf("The mask is: %x\n", mask);
	// masks x to get the wanted byte (for example CD000000, 78000000 in different cases shown below)
	int byte  = x & mask;
	//printf("byte masked: %x\n", byte);
	// gets the single byte, so it looks like 0xCD or 0x78 by shifting off the zeros on the right of the wanted byte
	byte = byte >> shift;
	//printf("byte: %x\n", byte);
	// since we have a single isolated byte (8 bits) we want to turn this into a 32 bit value, shift to the right 24 bits to add 6 zeros on the right
	byte = byte << 24;
	//printf("byte: %x\n", byte);
	// now we shift back 24 bytes to get rid of the unwanted zeros on the left and get the sign extension on the left.
	byte = byte >> 24;
	// turns the hex value to an unsigned integer to return (in project spec)
	unsigned int final = byte;
	printf("%08x\n", final);
	return final;

};


int main()
{
	extract(0x12345678, 0);
	extract(0xABCDEF00, 2);
	return 0;
};
