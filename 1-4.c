#include <stdio.h>
//Nicholas Fay
//01/14/1998


void printBytes(unsigned char *start, int len) 
{
	for (int i = 0; i < len; ++i) 
	{
		printf("  %.2x", start[i]);
	}
	printf("\n");
};


void printInt(int x) 
{
	printBytes((unsigned char *) &x, sizeof(int));
};

void printFloat(float x) 
{
	printBytes((unsigned char *) &x, sizeof(float));
};

void printShort(short x) 
{
	printBytes((unsigned char *) &x, sizeof(short));
};

void printDouble(double x) 
{
	printBytes((unsigned char *) &x, sizeof(double));
};

void printLong(long x) 
{
	printBytes((unsigned char *) &x, sizeof(long));
};

int main() 
{
	//Main function tests the above functions to analyze their outputs.
	//Some pretty interesting output, alot of zeros and random letters. I would think
	//it would have to do with some kind of leak in the memory. 
	printInt(10);
	printFloat(10);
	printShort(10);
	printDouble(10);
	printLong(10);

};
