#include <stdio.h>

/* question 3 */
int ques3(int x){
    int y = !x;
    int z = x >> 31;
    z = z | y;

    return !z;
}//if x is positive return 1 else return 0

int ans3(int x){
	if(x>0){
		return 1;
	}else {return 0};
}

int main () {
	int x = 1;
	int y = 0;
	int z = -1;

	printf("ques3 returns 1 if a number is greater than 0 and 0 otherwise\n 1: %d\n 0: %d\n -1: %d\n", ques3(1), ques3(0), ques3(-1));


}