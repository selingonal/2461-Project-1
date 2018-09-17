int ques7(int x) {

    return x & (~x+1);
}
/*Answer to Part B*/
//if x is even, the rightmost bit is returned 
//if x is odd, 1 is returned 

int getRightOneBitPosition(int x)
{
    return log2(x&-x)+1; //power to which 2 should be raised
}
int exponential(int y)
{
    int result=0;
    for (int i=1; i<y; i++)
    {
        result+= 2 * 2;
    }
    if (y==1)
    {
        result =2; 
    }
    return result; // the value at the correct location
}
int ans7(int x){
    int k;
    int y;
    y = log2(x&-x)+1; //power to which 2 should be raised
    if (y !=1)
    {
     y = y-1;
    }
    //odd
    if (x % 2 == 1) {
        return 1;
    }
    return pow(2,y);
}

int main()
{
    int x;
    x = 6; //even number that isn't a power of 2 
    
    int z;
    int q;
    q = ques7(x);
    z = ans7(y,x);
    printf("%d\n", q);
    printf("%d", z);
}

