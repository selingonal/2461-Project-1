#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ques5(int x) {
  // if x is odd, result here is 1000...0, if x is even, result is 0000...0
    int result = (x<<31);
  // if x is odd, result becomes 1111...1, if x is even, result is 0000...0
    result = (result >> 31);
  // x returns -1 if odd and 0 if positive
    return result;

}

int ans5(int x){
  if(x%2 == 0){
    return 0;
  }
  else if(x%2 == 1){
    return -1;
  }
}

int main(){
  int param;
  int resultQues;
  int resultAns;
  
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param);
  
  resultQues = ques5(param);
  resultAns = ans5(param);
  
  if (resultQues == 0 )
    printf("The number you passed into QUES was even\n");
  else
    printf("The number you passed into QUES was odd\n");
   
  if (resultAns == 0)
    printf("The number you passed into ANS was even\n");
  else
    printf("The number you passed into ANS was odd\n");
  
}
