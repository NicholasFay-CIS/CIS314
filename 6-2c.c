#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

//Nicholas Fay 
//part 6-2 C code


void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for(i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {
	int i = 0;
	//creates 4 sum variable and set them equal to 0.0
	float sum0, sum1, sum2, sum3 = 0.0f;
        //incriments i by 4 for the 4 way loop unrolling	
	for(i = 0; i < length; i+=4)
	{
		//Loop unrolling with the 4 accumulators
		sum0 += u[i] * v[i];
		sum1 += u[i+1] * v[i+1];
		sum2 += u[i+2] * v[i+2];
		sum3 += u[i+3] * v[i+3];
	}
	//Get the remainder
	for(;i < length; ++i)
       	{
		sum0 += u[i] * v[i];
	}
	//Total of the 4 accumulators
	*dest = sum0 + sum1 + sum2 + sum3;
}


int main()
{
	//Testing Cases
	//This is test for inner
	float u0[100] = {1.0f, 2.0f, 3.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	float v0[100] = {1.0f, 3.0f, 5.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f};
	float *u = u0;
	float *v = v0;
	int len = 100;
	float dest = 0.0f;
	float *desT = &dest;
	struct timeval start1;
	struct timeval end1;
        //Start Time for the inner 1
	//run a loop to get more accurate data
	gettimeofday(&start1, 0);
	for(int i = 0; i < 5000; i++)
	{

		inner(u, v, len, desT);
	}
	gettimeofday(&end1, 0);
	double seconds_inner = (double)(end1.tv_sec - start1.tv_sec) + (double)(end1.tv_usec - start1.tv_usec) / 100000;
	//End time inner loop
	//Tests for inner loop 2
	float U0[100] = {1.0f, 2.0f, 3.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	float V0[100] = {1.0f, 3.0f, 5.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f};
	float *U = U0;
	float *V = V0;
	int Len = 100;
	float Dest = 0.0f;
	float *DesT = &Dest;
	//Start the inner2 test
	struct timeval start2;
	struct timeval end2;
	gettimeofday(&start2, 0);
	//run a loop to get more accurate data
	for(int i = 0; i < 5000; i++)
       	{

		inner2(U, V, Len, DesT);
	}
	gettimeofday(&end2, 0);
	//calculate total run time for both functions
	//double seconds_inner = (double)(end1.tv_sec - start1.tv_sec) + (double)(end1.tv_usec - start1.tv_usec) / 100000;
	double seconds_inner2 = (double)(end2.tv_sec - start2.tv_sec) + (double)(end2.tv_usec - start2.tv_usec) / 100000;	
	printf("Time for inner:  %f\n", seconds_inner);
	printf("Time for inner2: %f\n", seconds_inner2);




}


