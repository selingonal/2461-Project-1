#include <stdio.h>

/* question 9 */

int ques9(int x, int n, int c) {
    int n8 = n << 3;			// Set n8 eqaul to 8n
    int mask = 0xff << n8;		// Set mask equal to 255 << 8n, if n>4, mask = 0, if n = 0 you get 255*2
    int cshift = c << n8;
    int z= (x & ~mask);

    return (z  | cshift);
}

int ans9(int x, int n, int c) {
	return 0;
}

int main () {
	printf("ques9(%d, %d, %d): %d\n", 0,0,0,ques9(0,0,0));
	printf("ques9(%d, %d, %d): %d\n", 1,1,1,ques9(1,1,1));
	printf("ques9(%d, %d, %d): %d\n", 4,4,12,ques9(4,4,12));
	printf("ques9(%d, %d, %d): %d\n", 8,9,10,ques9(8,9,10));
}
