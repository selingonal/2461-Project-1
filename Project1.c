#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* QUESTION 1*/

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



/* QUESTION 2*/
int ques2(int x) {
  /* 
    The line below shifts x's bits over 31 spaces, this means that if x < 0 , mask will be all 1's
    if x is > 0, mask will be all 0's 
  '*/
    int mask = x>>31; 
  // if x > 0, returns x, if x < 0 returns NOT x
    int y= (x ^ mask);
  // if x > 0, z returns 0, if x < 0, x returns 1
    int z = (~mask + 1);

   //Returns |x| if x is > or < 0, the absolute value of x
    return (y+z);
}

int ans2(int x){
  x = abs(x);
  return x;
}



/* QUESTION 3*/
int ques3(int x){
    int y = !x;			//Set y to 1 if x is 0 and 0 otherwise
    int z = x >> 31;	//Set z to the sign bit of x, 1 if negative 0 if positive
    z = z | y;			//Set z to1 if x is zero or if x is negative

    return !z;			//Return not z: 1 if x > 0 and 0 in all other cases
}

int ans3(int x){
	if(x>0){		//If x is greater than 0, return 1
		return 1;
	}
	return 0;		//Otherwise, return 0
}

int main () {
	int x;
	printf("Enter an integer: ");
	scanf("%d", &x);
	printf("\nques3(%d) returns 1 if x>0: %d\n", x, ques3(x));
	printf("ans3(%d) returns 1 if x>0: %d\n", x, ans3(x));

}






/* QUESTION 4*/

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
    int result=0;
    for (int i=0; i<y; i++)
    {
        result+= 2 * 2;
    }
    return result;
}



/* QUESTION 5*/
int ques5(int x) {
  // if x is odd, result here is 1000...0, if x is even, result is 0000...0
    int result = (x<<31);
  // if x is odd, result becomes 1111...1, if x is even, result is 0000...0
    result = (result >> 31);
  // x returns -1 if odd and 0 if even
    return result;

}

int ans5(int x){
  if(x%2 == 0){
    return 0;
  }
  else if(x%2 == 1){
    return -1;
  }
}


/* QUESTION 6*/
int ques6(void) {
    int byte = 0x55;			//Set byte to 85 (hexadecimal to deciaml) 01010101
    int word = byte | byte<<8;	//Set word to byte plus byte*2^8	0101010101010101

    return word | word<<16;		//Return word plus word*2^16: 01010101010101010101010101010101 = 1431655765
}

int ans6(){
	return 1431655765;
}


int main () {
	printf("ques6 simply returns the large numgber %d using 3 lines \n", ques6());
	printf("ans6 returns the number %d in 1 line \n", ans6());
}



/* QUESTION 7*/
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



/* QUESTION 8*/
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




/* QUESTION 9*/
int ques9(int x, int n, int c) {
    int n8 = n << 3;			// Set n8 eqaul to 8n (byte shift)
    //255 largest 8 bit number, shifting by 8 bits (1 byte) at a time
    int mask = 0xff << n8;		// Set mask equal to 255 shifted to the nth byte
    int cshift = c << n8;		// Set cshift equal to c shifted to the nth byte
    int z= (x & ~mask);			// Get everything but the nth byte of x

    return (z  | cshift);		//Replace the nth byte in x with the 0th byte in c
}

int ans9(int x, int n, int c) {
	int mask = 255 << (8*n);	//Shift 1 byte mask to nth byte
	int new_byte = c << (8*n);	//Shift 0th byte in c to nth byte
	return (new_byte | (x & ~mask));	//Replace nth byte in x with 0th yte in c and return
}




/* QUESTION 10*/
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





/* QUESTION 11*/
int ques11(int x, int y) {
 
  // only keeps the sign of x, 32 1's or 32 0's
	int a = x >> 31; 
  // only keeps the sign of y, 32 1's or 32 0's
	int b = y >> 31;
  /*
    the return statement has a lot of operators
    here's how they break down:
    will return -1 if:
        - x is negative and y is positive
        - y is positive and the absolute value of -x is less than y
        - y is negative and the absolute value of +x is less than y
    will return 0 in all other possible cases. 
  */
  return !((!a & b) | (!(a ^ b) & (y+~x)>>31));
}

int ans11(int x, int y){
  if (x < y || abs(x) < y || (x < 0 && y > 0) ) return -1;
  else return 0;
}





/* QUESTION 12*/
int ques12(int x, int m, int n) {
    int a = ~m+1;	// Set a to 2's complement of m or -m
    int b = ~x +1;	// Set b to 2's complement of n or -n
    // Compare x to m and n
    a = x + a;		// Set a to x + a or x-m 
    b = b + n;		// Set b to b + n or n-x

    // If x is between m and n return 1, otherwise return 0
    return !((a|b) >> 31);	// Return the inverse of the sign bit of bitwise a OR b 
}

int ans12 (int x, int m, int n) {
	if(x>=m && x<=n){	//If x is between m and n (inlcusive) return 1
		return 1;
	}
	return 0;			//Otherwise return 0
}







/* QUESTION 13*/
int ques13(int x) {

    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8);
    mask2 += mask2 << 16;
    mask1 = mask2 ^ (mask2 << 1);
    mask4 = 0x0F + (0x0F << 8);
    mask4 += mask4 << 16;
    mask8 = 0xFF + (0xFF << 16);
    mask16 = 0xFF + (0xFF << 8);

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}

/*Answer to Part B*/ 
//counts number of 1's in binary representation 
int ans13(int x) {
    int count=0;
    while (x)
    {
        count += x & 1; //adds to the count only if there's a 1 present (AND operator)
        x >>= 1;        //shift and assign new x position  
    }
    return count;
}
//decimal to binary conversion
int convert(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        return (x % 2 + 10 * convert(x / 2));
    }






/* QUESTION 14*/
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


  
  
  
/* QUESTION 15*/
  
int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n);	// Set temp to 2^n
    int z = temp + ~0;		// Set z to temp - 1 or 2^n-1
    // if x is less than 2^n, return x, otherwise return x mod 2^n
    return (z & x);			//return bitwise and of z nd x
}

int ans15(int x, int n) {
	return (x % (1 << n));	//Return x mod 2^n, the remainder when diving x by 2^n
}


