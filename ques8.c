#include <stdio.h>

int ques8(int x) {
  // if x > 0, y = 0, if x < 0, y = -1
    int y = x >> 31;
  // z will always return x
    int z = !!x;

  // returns 0 if x > 0, returns x if x < 0.
    return y | z;
}

int ans8(int x){
  if (x<0)
    return -1;
  else
    return 0;
}

int main(){
  int param;
  
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param);

  if (ques8(param) == )
    printf("The number you entered was positive.\n");
 
  else if (ques8(param) != param)
    printf("The number you entered was negative\n");
  printf("\n\n\n\n\n\n\n");
  if (ans8(param) == 0)
    printf("The number you entered was positive\n");
 
  else if(ans8(param) != param)
    printf("The number you entered was negative\n");

}