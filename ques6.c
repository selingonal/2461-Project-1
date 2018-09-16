#include <stdio.h>

int ques6(void) {
    int byte = 0x55;
    int word = byte | byte<<8;

    return word | word<<16;
}

int ans6(){
	return 1431655765;
}

//return 1431655765 or 01010101010101010101010101010101

int main () {
	printf("ques6 simply returns the large numgber %d using 3 lines \n", ques6());
	printf("ans6 returns the number %d in 1 line \n", ans6());
}