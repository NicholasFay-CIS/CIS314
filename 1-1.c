#include<stdio.h>
//Nicholas Fay
//01/13/2019
//project 1-1
unsigned int combine(unsigned int x, unsigned int y)
{
	{
		unsigned int x_mask, y_mask, combined_hex, x_needed, y_needed;
		//Keeps the first 8 bits of the hex, 0xFFFFFFFF -> 0x000000FF
		x_needed = x >> 24;
		//Keeps the last last 24 bits, 0xFFFFFFFF -> 0xFFFFFF00
		y_needed = y << 8;
		//gets rid of all the unwanted zeros from original shift, 0x000000FF -> 0xFF000000
		x_mask = x_needed << 24; 
		//gets rid of all the unwanted zeros from the original shift, 0xFFFFFF00 -> 0x00FFFFFF
		y_mask = y_needed >> 8;
		//uses the or bitwise operatior to combine the two hex values
		combined_hex = x_mask | y_mask;
		return combined_hex;
	}
};

int main()
{
	//Test Cases for combine function
	printf("0x%x\n", combine(0x12345678, 0xABCDEF00));
	printf("0x%x\n", combine(0xABCDEF00, 0x12345678));
	return 0;
};
