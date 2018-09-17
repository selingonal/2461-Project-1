#include <stdio.h>

int ques8(int x) {
  // if x > 0, y = 0, if x < 0, y = -1
    int y = x >> 31;
  // z will always return 1
    int z = !!x;
  // returns 1 if x > 0, returns -1 if x < 0, and 0 for x = 0.
    return y | z;
}

int ans8(int x){
  if (x<0) return -1;
  else if(x==0) return 0;
  else return 1;
}

int main(){
  int param;
  
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param);

  if (ques8(param) == 1)
    printf("The number you entered was positive.\n");
  else if (ques8(param) == -1)
    printf("The number you entered was negative\n");
  else 
    printf("You entered 0.\n");
  

  
   
  if (ans8(param) == 1)
    printf("The number you entered was positive\n");
  else if(ans8(param) == -1)
    printf("The number you entered was negative\n");
  else 
    printf("You entered 0.\n");


}