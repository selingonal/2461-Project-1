int ques1(int x) {
    int z;
    int y  = ~x+1;
    z= (~(y|x));
    z = (z >> 31);

    return (z & 1);

}
/* Answer to PART B: */
// the function always returns zero regardless of what the input is 
int ques1(int x){
    x=0; 
    return x; 
}
