#include <stdio.h>
// Nicholas Fay
// 01/16/19
// part 2-1

int mask(int n)
{
	// we are handling values from [1, 31] so subtract 1 from 32
	// When we shift 1 to the left by n, we get one greater than the mask we want, so we must subtract 1 to get the appropriate mask. 
	int mask = (1 << n) - 1;
	printf("0x%x\n", mask);
	return mask;
};


int main()
{
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(31);
	return 0;
};
