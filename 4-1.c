#include <stdio.h>
// Nicholas Fay
// part 4-1
//This is a tag, the start of the for loop
//loop:
//	sets the %rcx register to hold the data of b
//	movq %rsi, %rcx
//      set mask equal to one 
//	movl $1, %edx
//	set result equal to zero
//	movl $0, %eax
//.L2:
//	If source and destination regiters difference is zero, then sets a flag to 1 if true and 0 if false (q cuz 64 bit)
//	testq %rdx, %rdx
//	if the above register (rdx) is zero then jump to L4 flag.
//	je	.L4
//	setting register 8 equal to the mask
//	movq %rdx, %r8
//	means %r8 = %rdi | %r8 a is or'ed with the contents in register 8 which should be the mask
//	org  %rdi, %r8
//	means %rax = %rdi | %rax, stored in return variable/register rax return variable is created by a | result
//	org  %r8, %rax
//	means to shift %rdx (mask) to the right by %cl (lower order bits from the cl register)
//	sarq %cl, %rdx
//	No matter what jump back to Tag L2 and check testq again, 
//	jmp  .L2
//.L4:
//returns the final result
//	ret 

long loop(long a, long b) 
{
	long result = 0;
	//masked the result until the mask is zero
	for (long mask = 1 ; mask != 0 ; mask >>= b)
	{
		//updates result
		result |= (a | mask);
	}
	return result;
};

int main() 
{
	//Tests for loop function
	int x, y, z, a, b;
	x = loop(1, 5);
	y = loop(2, 4);
	z = loop(3, 3);
	a = loop(4, 2);
	b = loop(5, 1);
	printf("%d, %d, %d, %d, %d\n", x, y, z, a , b);
}
