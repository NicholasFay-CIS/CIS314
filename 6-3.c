#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
//Nicholas Fay

float* createArray(int size) {
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i) {
		// 50% chance that a[i] is 0.0f, random value on the range
		// [0.76, 1.26] otherwise.
		float r = rand()/ (float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
	}
	return a;
}
// original function
float f(float *a, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}
//Constructed Function
float g(float *a, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		prod *= a[i];
	}
	return prod;
}

int main() {
	float *Array = createArray(10000);
	struct timeval starttime;
	//start the clock
	gettimeofday(&starttime, 0);
	float product = f(Array, 10000);
	//end the closk
	struct timeval endtime;
	gettimeofday(&endtime, 0);
	//Find the total amount of time the function took
	double seconds = (double)(endtime.tv_sec - starttime.tv_sec) + (double)(endtime.tv_usec - starttime.tv_usec) / 100000;
	printf("The output of f: %f\n", product);
	printf("Total time taken by CPU: %f\n", seconds);
	// Create the second Array
	//float *Array2 = createArray(10000);
	int count = 0;
	for (int i = 0; i < 10000; i++) 
	{
		if(Array[i] != 0.0f){
			count++;
		}
	}
	//Creates the second array 
	float *array_2 = malloc(sizeof(float) * 10000);
	//sets up j interator
	int j = 0;
	for (int i = 0; i < 10000; i++){
		//if the element is non zero
		if(Array[i] != 0.0f){
			array_2[j] = Array[i];
			//add to the j iterator so no zeros are put in
			j++;
		}
	}
	// create the start time
	struct timeval startTime;
	gettimeofday(&startTime, 0);
	//get the total product
	float product2 = g(array_2, j);
	//Free the first and  second array
	free(Array);
	free(array_2);
	//End the clock
	struct timeval Endtime;
	gettimeofday(&Endtime, 0);
	double secs = (double)(Endtime.tv_sec - startTime.tv_sec) + (double)(Endtime.tv_usec - startTime.tv_usec) / 100000;
	//This should show that g is the same result with a much faster run time
	//G is about 1/3 the time it takes f to run
	printf("The output of g: %f\n", product2);
	printf("The time taken by the CPU: %f\n", secs);
	return 0;

}
