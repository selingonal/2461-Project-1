#include <stdio.h>
#include <math.h>
int exponential(int);
int ans4(int);
int ques4(int);

int main() {
    int n;
    n = 32;
    int y;
    y = ques4(n); 
    printf("%d", y); //y and z match 
    int z;
    z = ans4(n);
    printf("%d", z); //y and z match 

}
int ques4(int n) {
    int x = (!!n) << 31;
    x = x >> 31;
    int y = (1 << 31);
    y = y >> (n + (~0));

    return x & y;
}
/* Answer to Part B */ 

int ans4(int n)
{
    int y = 32-n;
    int z = ~(exponential(y));
    return z;
}
int exponential(int y)
{
    int i;
    int result=0;
    for (i=0; i<y; i++)
    {
        result+= 2 * 2;
    }
    return result;
}
