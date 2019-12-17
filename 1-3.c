#include<stdio.h>
//Nicholas Fay
//01/14/1998
//part 1-3

int evenBit(unsigned int x)
{
	unsigned int mask = 0x55555555;
	unsigned int x_masked = x & mask;
	return x_masked != 0;
};

int main()
{
	int x = evenBit(0x1);
	printf("%d\n", x);
	int y = evenBit(0x2);
	printf("%d\n", y);
	int z = evenBit(0x3);
	printf("%d\n", z);
	int a = evenBit(0x4);
	printf("%d\n", a);
	int b = evenBit(0xFFFFFFFF);
	printf("%d\n", b);
	int c = evenBit(0xAAAAAAAA);
	printf("%d\n", c);
	int d = evenBit(0x55555555);
	printf("%d\n", d);
};

