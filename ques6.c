#include <stdio.h>

int ques6(void) {
    int byte = 0x55;			//Set byte to 85 (hexadecimal to deciaml) 01010101
    int word = byte | byte<<8;	//Set word to byte plus byte*2^8	0101010101010101

    return word | word<<16;		//Return word plus word*2^16: 01010101010101010101010101010101 = 1431655765
}

int ans6(){
	return 1431655765;
}


int main () {
	printf("ques6 simply returns the large numgber %d using 3 lines \n", ques6());
	printf("ans6 returns the number %d in 1 line \n", ans6());
}