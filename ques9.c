#include <stdio.h>

/* question 9 */

int ques9(int x, int n, int c) {
    int n8 = n << 3;			// Set n8 eqaul to 8n (byte shift)
    //255 largest 8 bit number, shifting by 8 bits (1 byte) at a time
    int mask = 0xff << n8;		// Set mask equal to 255 shifted to the nth byte
    int cshift = c << n8;		// Set cshift equal to c shifted to the nth byte
    int z= (x & ~mask);			// Get everything but the nth byte of x

    return (z  | cshift);		//Replace the nth byte in x with the nth byte in c
}

int ans9(int x, int n, int c) {
	int byte = 8*n;
	int mask = 255 << byte;
	int new_byte = c << byte;
	return (new_byte | (x & ~mask));
}

int main () {
	int x;
	int n;
	int c;
	printf("Enter three integers: ");
	scanf("%d %d %d", &x, &n, &c);
	printf("ques9(%d, %d, %d) replaces the nth byte in the %d with the nth byte in %d, giving %d", x,n,c,x,c,ques9(x,n,c));
	printf("ans9(%d, %d, %d) replaces the nth byte in the %d with the nth byte in %d, giving %d", x,n,c,x,c,ans9(x,n,c));
}
