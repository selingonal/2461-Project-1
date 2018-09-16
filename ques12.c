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
	if(x>=m && x=<n){
		return 1;
	}
	return 0;
}

int main () {
	printf("ques12(1,2,3): %d\n", ques12(1,1,3)); 
	printf("ques12(4,2,5): %d\n", ques12(4,2,4));
	printf("ques12(7,10,3): %d\n", ques12(7,10,10));
	printf("ques12(1,1,1): %d\n", ques12(1,1,10));

	printf("ans12(%d,%d,%d): %d\n", 1,2,3,ans(1,2,3));
	printf("ans12(%d,%d,%d): %d\n", 5,4,6,ans(5,4,6));
	printf("ans12(%d,%d,%d): %d\n", 9,10,8,ans(9,10,8));
	printf("ans12(%d,%d,%d): %d\n", 1,1,1,ans(1,1,1));
}