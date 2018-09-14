#include <stdio.h>

/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1;
    int b = ~x +1;
    a = x + a;
    b = b + n;

    return !((a|b) >> 31);
}
//if x>m and x<n return 1, else return 0

int ans12 (int x, int m, int n) {
	if(x>m and x<n){
		return 1;
	}
	return 0;
}

int main () {
	
}