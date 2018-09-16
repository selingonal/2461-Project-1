#include <stdio.h>

/* question 3 */
int ques3(int x){
    int y = !x;			//Set y to 1 if x is 0 and 0 otherwise
    int z = x >> 31;	//Set z to the sign bit of x, 1 if negative 0 if positive
    z = z | y;			//Set z to1 if x is zero or if x is negative

    return !z;			//Return not z: 1 if x > 0 and 0 in all other cases
}

int ans3(int x){
	if(x>0){		//If x is greater than 0, return 1
		return 1;
	}
	return 0;		//Otherwise, return 0
}

int main () {
	int x;
	printf("Enter an integer: ");
	scanf("%d\n", &x);
	printf("ques3(%d) returns 1 if x>0: %d", x, ques3(x));
	printf("ans3(%d) returns 1 if x>0: %d", x, ans3(x));

}