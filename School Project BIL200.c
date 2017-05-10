//Mehmet Cagri Aksoy 12105037560

#include <stdio.h>
#include <stdlib.h> //i defined necessary libraries

float *a, *b, *c;  //defined 3 pointers
int degree1, degree2; //i defined integers for functions

int x, len1, len2, i, start, end, j; //i defined integers for functions

float *downsampling(float *a , int degree1, int len1); //i defined integers for functions
void del(float *b, int, int, int);


int main() {
	//defined a,b Memory Allocations
	//type float size 100
	
	a = malloc(100 * sizeof(float));
	b = malloc(100 * sizeof(float));

	//io functions
	printf("Please enter:");
	printf("\n1 for downsampling of an array,\n2 for erasing selected part of an array,\n0 for exit the program,\n");
	scanf("%d", &x);
	//switch case function necessary for menu design
	switch (x) {
	case 1: 
		//if enter a value which is 1, run these loops.
		printf("Please enter the size of the floating point array:");
		scanf("%d", &len1);
		for (i = 0; i < len1; i++) {
			printf("Enter %dth element of array:", i + 1);
			scanf("%f", &a[i]);
		}
		printf("Your array:\n");
		//print array values:
		for (i = 0; i < len1; i++) {
			printf("%  .2f  ", a[i]);
		}
		printf("\nPlease enter the degree of downsampling:");
		scanf("%d", &degree1);

		downsampling( a, degree1, len1);
		
		printf("Downsampled array:\n");
		for (i = 0; i < len1/degree1; i++) {
			printf("  %.2f  ", a[i]);
		}
		break;

	case 2: 
		//Deleting range of array (if enter a value which is 2)
		printf("Please enter the size of the floating point array:");
		scanf("%d", &len2);
		for (j = 0; j < len2; j++) {
			printf("Enter %dth element of array:", j+1);
			scanf("%f", &b[j]);
		}
		printf("Your array:\n");

		for (j = 0; j < len2; j++) {
			printf("  %.2f  ", b[j]);
		}
		//enter the edge values
		printf("Please enter the start index of the part to be deleted:");
		scanf("%d", &start);
		printf("\nPlease enter the end index of the part to be deleted:");
		scanf("%d", &end);
		del(b, start, end, len2);
		printf("Input array after erasing selected part:\n");
		for (i = 0; i <= len2/(end-start+1); i++) {
			printf("  %.2f  ", b[i]);
		}
		break;
	case 0: 
		//exit the programme.
		return 0;
		break;
	default:  
		//the program says please enter a valid number when entered unsuitable value.
		printf("Please enter a valid number 0-1-2");
		break;
	}
}

float *downsampling(float *a, int degree1, int len1) {
	//downsampling function uses float a, degree1, len1 values
	//downsampling array sorting functions
	int len3 = len1 / degree1;

	for (i = 1; i <= len3; i++) {
		*(a+i-1) = *(a-1+degree1*i);
	}
	return a;
}

void del(float *b, int start, int end, int len2) {
     //del function uses float b, end and len2 values
	//range of deleting array functions
	int i = 1;
	for ( ; start<=end; start++) {
		*(b + start) = *(b + end+i);
		i++;
	}
	
}
//Mehmet Cagri Aksoy 12105037560
