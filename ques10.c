int ques10(int x) {
	int y = !!x;
	int z = (!(x+x));

    return y & z;
}
/* Answer to Part B*/ 
//will always return 0 

int ans10(int x){
  x=0;
  return x;
}
