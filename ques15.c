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
	return (x % (1 << n));	//Return x mod 2^n, the remainder when diving x by 2^n
}

int main () {
	int x;
	int n;
	printf("Enter two integers: ");
	scanf("%d %d\n", &x, &n);
	printf("ques15(%d, %d) returns the remainder when dividing %d by 2^%d: %d", x,n,x,n,ques15(x,n));
	printf("anss15(%d, %d) returns the remainder when dividing %d by 2^%d: %d", x,n,x,n,ans15(x,n));
}