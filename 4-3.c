#include<stdio.h>
#define N 4
//Nicholas Fay 
//part 4-3
typedef long array_t[N][N];

//original function
void transpose(array_t a) {
	for (long i =0; i < N; ++i)
	{
		for (long j = 0; j < i; ++j) {
			long t1 = a[i][j];
			long t2 = a[j][i];
			a[i][j] = t2;
			a[j][i] = t1;
		}
	}
};


//.L3:
//	stores the value of that rax points to in rcx
//	movq (%rax), %rcx
//	This has rsi hold the value that rdx points to
//	movq (%rdx), %rsi
//      This sets the return pointer to point to the value of rsi	
//	movq %rsi, (%rax)
//      have rax point to rsi's value	
//	movq %rcx, (%rdx)
//	This offsets j by 8 bits
//	addq $8, %rax
//	This offsets rdx by 32 bits  
//	addq $32, %rdx
//	if j is less than i (i is in register r9)
//	cmpq %r9, %rax
//	Jump if not equal to (from above statement), go to L3
//	jne .L3

//Build function 
void transpose_2(array_t a) {
	//points to the row/column at index 0, 0 (can be seen as starting value)
	long *start = &a[0][0];
	//loop for the rows
	for (long i = 0; i < N; ++i)
	{
		//loop for the columns
		for (long j = 0; j < i; ++j) {
			//gets the correct row index (1, 2, 3, 4) and adds the offset to get the right number next
			long *row = start + (N*i+j);
			//gets the correct column index and add the offset to get the next number ( 4 numbers past)
			long *column = start + (N*j+i);
			//This is storing the row index
			long temp = *row;
			//swaps row and column index values
			*row = *column;
			//index j is now index i
			*column = temp;
		}
	}
};

void printArray(array_t a) {
	//loop through all the row index's
	for (long i = 0; i < N; ++i)
	{
		//print start of curly bracket for new 2d list
		printf("{ ");
		//loop through all the column index's
		for (long j = 0; j < N; ++j)
		{
			//print the array at the row/column index until nothing left to print
			printf("%d ", a[i][j]);
		}
		//closing curly bracket for the lits
		printf("} \n");
	}
};

int main() {

	//given data to sort
	array_t array =  {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	//prints the array before
	printArray(array);
	//rearranges the array
	transpose_2(array);
	//prints the new 2d array
	printArray(array);
};
