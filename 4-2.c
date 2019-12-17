#include<stdio.h>
//Nicholas Fay
//part 4-2

//Given function
int sum(int n) {
	int i = 1;
	int result = 0;
	do {
		result += i;
		++i;
	} while (i <= n);
	return result;
};

//Built Function
long sum_2(long n) {
	if (n < 1) {
		return 0;
	}
	long i = 1;
	long result = 0;
	//Ensure that argument *n* is in %rdi, *i* is in %rcx, 
	//*result* is in %rax - do not modify.
	__asm__("movq %0, %%rdi # n in rdi;" :: "r" ( n ));
	__asm__("movq %0, %%rcx # i in rcx;" :: "r" ( i ));
	__asm__("movq %0, %%rax # result in rax;" :: "r" ( result ));
	//x86-64 code goes here 	
	__asm__(
		"Loop:;" // label for the do while loop
		"addq %rcx, %rax;" // adds to the final result, i is added to result
		"addq $1, %rcx;" // increments i by 1
		"cmpq %rdi, %rcx;" //compares i to n
		"jle Loop;" //jumps back to beginging of loop
	);
	//Ensure that *result* is in %rax for return - do not modify.
	__asm__("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	return result;
};


int main() {
	//Test Cases 
	long x;
	long y;
	long a;
	long b;
	a = sum(1);
	y = sum(3);
	b = sum(5);
	x = sum_2(7);
	printf("%d\n", a);
	printf("%d\n", y);
	printf("%d\n", b);
	printf("%ld\n", x);
};




