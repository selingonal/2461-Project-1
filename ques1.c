int ques1(int x) {
    int z;
    int y  = ~x+1; //y is the 2's complement of x 
    z= (~(y|x)); // OR of original and its 2's complement then take the complement 
    z = (z >> 31); //shifted right 31 bits 

    return (z & 1); // only if x is 0 will this AND operation be true and return 1 

}
/* Answer to PART B: */
// the function returns zero so long as the input isn't zero. In that case, it returns 1 
int ques1(int x){
    int y; 
    if (x==0)
    {
     y =1; 
    }
    else
    {
      y =0; 
    }
    return y; 
}
