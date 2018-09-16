#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ques2(int x) {
  /* 
    The line below shifts x's bits over 31 spaces, this means that if x < 0 , mask will be all 1's
    if x is > 0, mask will be all 0's 
  '*/
    int mask = x>>31; 
  // if x > 0, returns x, if x < 0 returns NOT x
    int y= (x ^ mask);
  // if x > 0, z returns 0, if x < 0, x returns 1
    int z = (~mask + 1);

   //Returns |x| if x is > or < 0, the absolute value of x
    return (y+z);
}

int ans2(int x){
  x = abs(x);
  return x;
}

 int main(){
  int param;
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param);

  printf("Ques2 returns: %d, the absolute value of your number.\n\n\n\n\n", ques2(param));
 
  printf("Ans2 returns: %d, the absolute value of your number\n", ans2(param));

   
 }