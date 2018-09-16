int ques7(int x) {

    return x & (~x+1);
}
/*Answer to Part B*/
//if x is even, x is returned
//if x is odd, 1 is returned 

int ans7(int x){
  int y; 
  //even
  if (x % 2 == 0) {
    y = x; 
  }
  else{
    y =1; 
  }
  return y; 
}

