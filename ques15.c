#include <stdio.h>
#include <math.h>

/* question 15 */

int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n);	// Set temp to 2^n
    int z = temp + ~0;		// Set z to temp - 1 or 2^n-1
    // if x is less than 2^n, return x, otherwise return x mod 2^n
    return (z & x);			//return bitwise and of z nd x
}

int ans15(int x, int n) {
	if(x<pow(2,n)){			//if x is less than 2^n, return x
		return x;
	}
	return (x%(pow(2,n)));	//Otherwise return x mod 2^n, the remainder when diving x by 2^n
}

int main () {
	printf("ques15(%d, %d): %d", 2, 4, ques15(2,4));
	printf("ques15(%d, %d): %d", 4, 2, ques15(4,2));
	printf("ques15(%d, %d): %d", 5, 7, ques15(5,7));
	printf("ques15(%d, %d): %d", 1, 0, ques15(1,0));
	
	

}