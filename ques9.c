#include <stdio.h>
#include <math.h>

/* question 9 */

int ques9(int x, int n, int c) {
    int n8 = n << 3;			// Set n8 eqaul to 8n (byte shift)
    //255 largest 8 bit number, shifting by 8 bits (1 byte) at a time
    int mask = 0xff << n8;		// Set mask equal to 255 shifted to the nth byte
    int cshift = c << n8;		// Set cshift equal to c shifted to the nth byte
    int z= (x & ~mask);			// Get everything but the nth byte of x

    return (z  | cshift);		//Replace the nth byte in x with the 0th byte in c
}

int ans9(int x, int n, int c) {
	int mask = 255 << (8*n);	//Shift to nth byte using 2^(8n)
	int new_byte = c << (8*n);	//Shift 0th byte in c to nth byte
	return (new_byte | (x & ~mask));	//Replace nth byte in x with 0th byte in c and return
}

int main () {
	int x;
	int n;
	int c;
	printf("Enter three integers: ");
	scanf("%d %d %d", &x, &n, &c);
	printf("\nques9(%d, %d, %d) replaces byte %d in %d with the 0 byte in %d, giving %d\n", x,n,c,n,x,c,ques9(x,n,c));
	printf("ans9(%d, %d, %d) replaces byte %d in %d with the 0 byte in %d, giving %d\n", x,n,c,n,x,c,ans9(x,n,c));
}
