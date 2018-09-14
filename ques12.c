#include <stdio.h>

/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1;	// Set a to 2's complement of m or -m
    int b = ~x +1;	// Set b to 2's complement of n or -n
    // Compare x to m and n
    a = x + a;		// Set a to x + a or a-n 
    b = b + n;		// Set b to b + n or n-x

    // If x is between m and n return 1, otherwise return 0
    return !((a|b) >> 31);	// Return the inverse of the sign bit of bitwise a or b 
}

int ans12 (int x, int m, int n) {
	if(x>m && x<n){
		return 1;
	}
	return 0;
}

int main () {
	printf("ques12 ")

}