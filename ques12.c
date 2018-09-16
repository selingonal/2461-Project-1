#include <stdio.h>

/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1;	// Set a to 2's complement of m or -m
    int b = ~x +1;	// Set b to 2's complement of n or -n
    // Compare x to m and n
    a = x + a;		// Set a to x + a or x-m 
    b = b + n;		// Set b to b + n or n-x

    // If x is between m and n return 1, otherwise return 0
    return !((a|b) >> 31);	// Return the inverse of the sign bit of bitwise a OR b 
}

int ans12 (int x, int m, int n) {
	if(x>=m && x<=n){	//If x is between m and n (inlcusive) return 1
		return 1;
	}
	return 0;			//Otherwise return 0
}

int main () {
	int x;
	int m;
	int n;
	printf("Enter 3 integers: ");
	scanf("%d %d %d", &x, &m, &n);
	printf("\n ques12(%d, %d, %d) determines whether %d is between %d and %d: %d\n", x,m,n,x,m,n,ques12(x,m,n));
	printf("ans12(%d, %d, %d) also determines whether %d is between %d and %d: %d\n", x,m,n,x,m,n,ans12(x,m,n));
}