#include <stdio.h>

int ques11(int x, int y) {
 
  // only keeps the sign of x, 32 1's or 32 0's
	int a = x >> 31; 
  // only keeps the sign of y, 32 1's or 32 0's
	int b = y >> 31;
  /*
    the return statement has a lot of operators
    here's how they break down:
    will return -1 if:
        - x is negative and y is positive
        - y is positive and the absolute value of -x is less than y
        - y is negative and the absolute value of +x is less than y
    will return 0 in all other possible cases. 
  */
  return !((!a & b) | (!(a ^ b) & (y+~x)>>31));
}

int ans11(int x, int y){
  if (x < y || abs(x) < y || (x < 0 && y > 0) ) return -1;
  else return 0;
}

int main(){
  
  int paramx, paramy;
  printf("Enter two numbers to be manipulated: \n");
  scanf("%d %d", &paramx, &paramy);
  
  if(ques11(paramx, paramy) == -1){
    printf("Your operation returned a positive number\n");
  }
  else{
    printf("Negative number\n");
  }

  
  if(ans11(paramx, paramy) == -1){
    printf("The operation returned a positive number\n");
  }
  else{
    printf("Negative number\n");
  }
  
}