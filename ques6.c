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
	
}