#include <stdio.h>

/* question 15 */

int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n);	// Set temp to 2^n
    int z = temp + ~0;		// Set z to temp + 1 or 2^n + 1

    // if x is zero or x has zeroes in the 1 and n places, return 0, otherwise return 1
    return (z & x);			//return bitwise and of z nd x
}

int ans15(int x, int n) {
	int z = 2**n + 1;
	return (z & x);
}

int main () {

}