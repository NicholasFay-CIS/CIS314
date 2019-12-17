#include <stdio.h>
// Nicholas Fay
// 01/18/2019
// part 2-3

int le(float x, float y) {
	unsigned int ux = *((unsigned int*) &x);
	unsigned int uy = *((unsigned int*) &y);
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; //drop sign bit of ux
	uy <<= 1; //drop sign bit of uy

	// TO DO SECTION: 
	// when the program executes we will see one being produced by a max of two of these operations
	// this is becuase the problem can be solved using 1 or 2 of the conditions below. 
	// condition meaning whether one is neg/ positive, if x > y etc..
        
	// This deals with the differencing negative zero and positive zero. Should be the condition to compute test case 2.
	int is_zero = (ux == 0 && uy == 0);
	//if the two integers are both positive numbers checking if they are 0 because 0 is positve sign bit. Through the test cases it is important for case 4/6.
	int is_pos = (((sx==0) & (sy==0)) & (ux <= uy));
	//if the two integers are both negative numbers. checks to see if the sign bit is 1 as that determines negativity. Through the test cases it is important for case3
	int is_neg = (((sx==1) & (sy==1)) & (ux <= uy));
	//if y is less than x will return a zero. Checks if x is smaller than y.
	int x_ismore = (sx > sy);
	// logical |'s to hold any one's that had been returned by any of the above conditions that proved to be true.
	int is_true = (is_pos | is_neg );
	is_true = (is_true | x_ismore);
	is_true = (is_true | is_zero);
	// Prints all the results of the above conditions
	//printf("x <= y: %d, positive: %d, negative: %d, zeros: %d\n", x_ismore, is_pos, is_neg, is_zero);
	printf("%d\n", is_true);
	return is_true;
};


int main()
{ 
	// Test cases labeled 1 - 8
	// 1
	le(-1.0f, 0.0f);
	// 2
	le(-0.0f, 0.0f);
	// 3
	le(-1.0f, -1.0f);
	// 4
	le(1.0f, 1.0f);
	// 5
	le(-1.0f, 0.0f);
	// 6
	le(0.0f, 1.0f);
	// 7
	le(1.0f, 0.0f);
	// 8
	le(0.0f, -1.0f);
	return 0;
};
