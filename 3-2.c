#include <stdio.h>
//Nicholas Fay
///01/31/2019
//3-2
long f(long a, long b, long c)
{
	//This program mimics the assembly code functionality we were given.
	//variable that stores value we will end up returning
	long rax;
	//c is equal to c plus b
	c = c + b;
	//a is equal to a times c
	a = a * c;
	//shift c to the left 63 bits
	c = c << 63;
	//shift c to the right 63 bits
	c = c >> 63;
	// set long var to be a
	rax = a;
	//xor var with c
	rax = rax ^ c;
	//return variable
	return rax;	
};



int main() 
{
	//creates variables to store values then print
	int x, y, z;
	x = f(1, 2, 4);
	y = f(3, 5, 7);
	z = f(10, 20, 30);
	printf("%ld\n", x);
	printf("%ld\n", y);
	printf("%ld\n", z);
};
