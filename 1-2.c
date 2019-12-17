#include <stdio.h>
//Nicholas Fay
//01/13/1028
//part 1-2



unsigned int replace(unsigned int x, int i, unsigned char b)
{
	//creates the mask used, for ex if i = 2, then (0xff << 16) -> 0xff0000
	unsigned int bit_mask = 0xff << (i << 3);
	//shifts the unsigned char to the correct bin location where it will be placed. for ex if b = 0xAB, i = 2, then (0xAB << 16) ->0xAB0000
	unsigned int b_shift = (b << (i << 3));
	//We want to use the masks complament so the mask can contain all ones except for the area we want to place our value b.
	//The space where we want to place b should be all zeros.
	unsigned int x_final = x & ~bit_mask;
	//returns the new hex number with the replacement of b in x.
	return x_final | b_shift;

};

int main()
{
	//Test Cases
	printf("0x%x\n", replace(0x12345678, 2, 0xAB));
	printf("0x%x\n", replace(0x12345678, 0, 0xAB));
	return 0;
};
