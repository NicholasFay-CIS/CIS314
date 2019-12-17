#include<stdio.h>
//Nicholas Fay
//7-2

unsigned int getOffset(unsigned int address)
{ 
	//this gets the offset by masking the address
	unsigned int Offset = 0x0000000F & address;
	return Offset;

}


unsigned int getSet(unsigned int address)
{
	//This gets the set by masking the address then shifting by 2
	unsigned int set = (0x000000F0 & address) >> 4;
	return set;

}

unsigned int getTag(unsigned int address) 
{

	//this gets the tag by masking the address then shifting by 8
	unsigned int tag = (0xFFFFFF00 & address) >> 8;
	return tag;


}


int main()
{
	unsigned int x = 0x12345678;
	unsigned int y = 0x87654321;
	printf("0x12345678: offset %x - tag: %x - set: %x\n", getOffset(x), getTag(x), getSet(x));
	printf("0x87654321: offset %x - tag: %x - set: %x\n", getOffset(y), getTag(y), getSet(y));







}

