#include <stdio.h>
#include <stdlib.h>
// Nicholas Fay
// part 3-1


//Struct IntArray, contains a data pointer and a length, indicating the input/list size
struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length)
{
	struct IntArray *arr;
	//allocates enough memory for the struct
        arr = (struct IntArray *)malloc(sizeof(struct IntArray));
	//Initializes the length of the data being received
	arr->length = length;
	//Mallocing enough space for an integer/data  pointer 
	arr->dataPtr = (int *)malloc(sizeof(int)*length);
	return arr;	
};

void freeIntArray(struct IntArray *arrayPtr)
{	//free the data pointer 	
	free(arrayPtr->dataPtr);
	//free the struct
	free(arrayPtr);
};

void readIntArray(struct IntArray *array)
{
	long final;
	char *pointer = NULL;
	int i = 0;
	for(i = 0; i<= array->length-1;) 
	{
		// mallocs enough memory for a 32 bit integer
		char *arr = malloc(sizeof(char)*32);
		printf("Enter int: ");
		//takes the users input 
		fgets(arr, 32, stdin);
		//converts the string input into a long 
		final = strtol(arr, &pointer, 10);
		// if the converted number is reasonable and non aphabetic/negative
		if (pointer && final > 0)
		{
			//Then add the data value to the given position in the data pointer
			array->dataPtr[i] = final;
			i++;
		}
		else
		{
			//promp user that there was an invalid input, user will want to enter valid input 
			printf("Invalid input \n");
		}
	}
};

void swap(int *xp, int *yp)
{
	//this swaps two variable values
	//uses temp variables to store information during transfer
	int swap0, swap1;
	swap0 = *xp;
	swap1 = *yp;
	*xp = swap1;
	*yp = swap0;
};

void sortIntArray(struct IntArray *array)
{
	int i, k;
	//first loop for i, the number being compared to
	for(i = 0; i<array->length-1; i++)
	{
		//values at k will be compared to values at i, starts one greater than i
		for(k = i+1; k<array->length; k++)
		{
			//if at index k the data is larger then at index i
			if(array->dataPtr[i] > array->dataPtr[k])
			{
				//use swap function to swap values
				swap(&array->dataPtr[i], &array->dataPtr[k]);
			}
		}
	}

};

void printIntArray(struct IntArray *array)
{
	int i;
	int k;
	printf("[ ");
	//prints each value of data that has been stored
	for(i=0; i<array->length;i++)
	{
		printf("%d ", array->dataPtr[i]);
		if(i<array->length-1)
		{
			//the last data member will not have a comma after it
			printf(", ");
		}
	}
	printf("]\n");
};

int main() 
{
	long final;
	char *pointer;
	int i = 0;
	//loop to accound for false user input
	while (i == 0)
	{
		//mallocs enough size for a 32 bit integer determining the length
		char *len = malloc(sizeof(int)*32);
		printf("Enter the length: ");
		//takes user input as a string
		fgets(len, 32, stdin);
		//converts the string to a long
		final = strtol(len, &pointer, 10);
		//if the long is non negative and non alphabetical, break out of the loop
		if(pointer && final > 0)
		{
			i++;
		}
		else
		{
			//else tell user there is an invalid input and stay in loop until an acceptable input in received
			printf("Invalid Input\n");
		}
	}
	//after breaking out of the group create and malloc an integer array
	struct IntArray *array = mallocIntArray(final);
	//read and obtain numbers from user
	readIntArray(array);
	//bubble sorts the numbers in the list
	sortIntArray(array);
	//displays the numbers in the list by printing them
	printIntArray(array);
	//free's all allocated memory 
	freeIntArray(array);
};




