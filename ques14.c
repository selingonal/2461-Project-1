#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ques14(int x) {
  
  int result = 0;
  int i;

  for (i = 0; i < 32; i++)
   result ^=  (x >> i) & 0x1;

   return result;
}

int ans14(int x){
  int count = 0; 
  while(x){
    count += x&1;
    x >>=1;
  }
  if (count % 2 == 1) return 1;
  else return 0;
  
}

int main(){
  int param;
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param);

  
  if (ques14(param) == 1){
    printf("There is an odd number of 1's in the string.\n");
  }
  else{
    printf("There is an even number of 1's in the string.\n");
  }
  if (ans14(param) == 1){
    printf("There is an odd number of 1's in the string.\n");
  }
  else{
    printf("There is an even number of 1's in the string.\n");
  }

  
}


