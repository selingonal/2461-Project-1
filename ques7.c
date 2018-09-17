int ques7(int x) {

    return x & (~x+1);
}
/*Answer to Part B*/
//if x is even, x is returned
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
    if (y ==1)
    {
        result = 2;
    }
    return result; // the value at the correct location 
}
int ans7(int y, int x){
    int k;
    //odd
    if (x % 2 == 1) {
        k =1;
    }
    else{
        k = exponential(y);
    }
    return k;
}

int main()
{
    int y;
    int z;
    int x = 18;
    y = getRightOneBitPosition(x);
    if (y!= 1)
    {
        y = y-1;
    }
    z = ans7(y,x);
    printf("%d", z);

}



