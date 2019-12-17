#include<stdio.h>
//Nicholas Fay
//6-1


int f(int a , int b, int c, int d, int n) {
       int result = 0;
       for (int i = 0; i < n; ++i) 
       {
	       for (int j = 0; j < n; ++j) 
	       {
		       result += a * b + i * c * d + j;
	        }
	}
       return result;
}
	          
int f_new(int a, int b, int c, int d, int n) {
	int result = 0;
	//pulls out the multiplication of a,b and c,d
	int part_a = a * b;
	int part_b = c * d;
	//incrementor for the i * c so there is no multiplication needed
	int bi = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result += part_a + bi + j;
			//result += a * b + i * c * d + j;
		}
		//updates the i * c counter
		bi += part_b;
	}
	return result;
}


int main() {
	//test for original fucntion
	int x = f(1,2,3,4,5);
	int y = f(2,3,4,5,6);
	int z = f(6,5,4,3,2);
	int q = f(5,4,3,2,1);
	printf("%d, %d, %d, %d\n", x, y, z, q);
	//test for new function
	int _x = f_new(1,2,3,4,5);
	int _y = f_new(2,3,4,5,6);
	int _z = f_new(6,5,4,3,2);
	int _q = f_new(5,4,3,2,1);
	printf("%d, %d, %d, %d\n", _x, _y, _z, _q);
	return 0;


}
