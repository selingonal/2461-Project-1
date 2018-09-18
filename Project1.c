/*
Group No: 4
Team Members: Selin Onal, Tuhina Dasgupta, Sarah Morin
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//ANSWER 7 requires this compilation instruction: gcc -o Project1 -std=c99 Project1.c -lm

/* QUESTION 1*/
int ques1(int x) {
    int z;
    int y  = ~x+1; //y is the 2's complement of x 
    z= (~(y|x)); // OR of original and its 2's complement then take the complement 
    z = (z >> 31); //shifted right 31 bits 

    return (z & 1); // only if x is 0 will this AND operation be true and return 1 

}

// The function returns zero so long as the input isn't zero. In that case, it returns 1 
int ans1(int x){
    if (x==0)
    {
      return 1; 
    }
    return 0;   
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
  // basic C command to handle absolute value
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


/* QUESTION 4*/
int ques4(int n) {
    int x = (!!n) << 31;    //!!n is 1 if n is anything besides 0, if n is 0 then !!n is 0
    x = x >> 31; 	          //either a string of zeros or a string of ones
    int y = (1 << 31);      // equals 1 followed by a string of zeros 
    y = y >> (n + (~0));    // y is right shifted by n added to a string of ones 

    return x & y; //result is ~(2^(32-n))
}

int ans4(int n)
 {
     int y = 32-n; // number to which 2 is raised
     double z = pow(2,y);
     return ~((int)z-1);    // take complement of 2^y to get result and subtract 1 (z)
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
  // Conditions determine whether c is even or odd through modular arithmatic
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

int ans6(void){
	return 1431655765;
}


/* QUESTION 7*/
int ques7(int x) {
    //if x is even, rightmost one's place value is returned
    //if x is odd, 1 is returned 
    return x & (~x+1);
}

int getRightOneBitPosition(int x)
{
    return log2(x&-x)+1; //power to which 2 should be raised
}
int exponential(int y)
{
    int result=0;
    int i; 
    for (i=1; i<y; i++)
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

  if (x<0) return -1; //returns -1 for negative numbers
  else if(x==0) return 0; // returns 0 for 0 only
  else return 1; // returns 1 for positive numbers
}


/* QUESTION 9*/
int ques9(int x, int n, int c) {
    int n8 = n << 3;		  	 // Set n8 eqaul to 8n (byte shift)
    //255 largest 8 bit number, shifting by 8 bits (1 byte) at a time
    int mask = 0xff << n8;	// Set mask equal to 255 shifted to the nth byte
    int cshift = c << n8;		// Set cshift equal to c shifted to the nth byte
    int z= (x & ~mask);			// Get everything but the nth byte of x

    return (z  | cshift);		//Replace the nth byte in x with the 0th byte in c
}

int ans9(int x, int n, int c) {
	int mask = 255 << (8*n);	        //Shift 1 byte mask to nth byte
	int new_byte = c << (8*n);	      //Shift 0th byte in c to nth byte
	return (new_byte | (x & ~mask));	//Replace nth byte in x with 0th yte in c and return
}


/* QUESTION 10*/
int ques10(int x) {
	int y = !!x;
	int z = (!(x+x));

    return y & z;
    //will always return 0 
}

int ans10(int x){
  return 0;
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
    will return 1 if:
        - x is negative and y is positive
        - y is positive and the absolute value of -x is less than y
        - y is negative and the absolute value of +x is less than y
    will return 0 in all other possible cases. 
  */
  return !((!a & b) | (!(a ^ b) & (y+~x)>>31));
}

int ans11(int x, int y){
  // I've made the function return these conditions specifically because these are the cases I defined will return 1.
  if (x < y || abs(x) < y || (x < 0 && y > 0) ) return 1;
  else return 0;
}


/* QUESTION 12*/
int ques12(int x, int m, int n) {
    int a = ~m+1;	  // Set a to 2's complement of m or -m
    int b = ~x +1;	// Set b to 2's complement of n or -n
    
    // Compare x to m and n
    a = x + a;		  // Set a to x + a or x-m 
    b = b + n;		  // Set b to b + n or n-x

    // If x is between m and n return 1, otherwise return 0
    return !((a|b) >> 31);	// Return the inverse of the sign bit of bitwise a OR b 
}

int ans12 (int x, int m, int n) {
	if(x>=m && x<=n){	//If x is between m and n (inlcusive) return 1
		return 1;
	}
	return 0;			   //Otherwise return 0
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

    //Counts number of 1's in binary representation of x  
    return x;
}

int ans13(int x) {
    int count=0;
    while (x)
    {
        count += (x & 1); //adds to the count only if there's a 1 present (AND operator)
        x >>= 1;        //shift and assign new x position  
    }
    return count;
}


/* QUESTION 14*/
 int ques14(int x) {
  
  int result = 0;             
  int i;

  for (i = 0; i < 32; i++)    //Iterates through each bit
   result ^=  (x >> i) & 0x1; //Gets last bit of x, xor= into result
  //If result is 0, it becomes 1, if its 1 it becomes 0
  //Determines whether the number of 1's in the binary string is even or odd
   return result;
}

int ans14(int x){
  // counts the number of 1's in the binary string representation of the number
  int count = 0; 
  while(x){
    count += x&1;
    x >>=1;
  }
  // here we check the count to see if there is an even or odd amount of 1's in the string
  //returns 1 or 0 accordingly 
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

/*Examples in main()*/
int main () {
  int param1;
  int param2;
  int param3;

  //Question 1
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  printf("Ques1 returns 1 if your number is 0, otherwise it returns 0: Ques1(%d) = %d\n", param1, ques1(param1));
  printf("Ans1 returns 1 if your number is 0, otherwise it returns 0: Ans1(%d) = %d\n", param1, ans1(param1));
  
  //Question 2
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  printf("Ques2 returns: %d, the absolute value of your number.\n", ques2(param1));
  printf("Ans2 returns: %d, the absolute value of your number\n", ans2(param1));
  
  //Question 3
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  printf("Ques3 returns 1 if x>0: %d\n", ques3(param1));
  printf("Ans3 returns 1 if x>0: %d\n", ans3(param1));
  
  //Question 4
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  printf("Ques4 returns ~(2^(32-%d)): %d\n", param1, ques4(param1));
  printf("Ans4(%d) returns %d\n", param1, ans4(param1));
  
  //Question 5
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  
  if (ques5(param1) == 0 )
    printf("The number you passed into QUES was even\n");
  else
    printf("The number you passed into QUES was odd\n");
   
  if (ans5(param1) == 0)
    printf("The number you passed into ANS was even\n");
  else
    printf("The number you passed into ANS was odd\n");
  
  //Question 6
  printf("ques6 simply returns the large numgber %d using 3 lines \n", ques6());
  printf("ans6 returns the number %d in 1 line \n", ans6());
  
  //Question 7
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  printf("Ques7 returns the place of the rightmost 1 in the binary string: %d\n", ques7(param1));
  int y = getRightOneBitPosition(param1);
  if (y!= 1){
       y = y-1;
    }
  printf("Ans7(%d): %d\n", param1, ans7(y,param1));
  
  //Question 8
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);

  if (ques8(param1) == 1)
    printf("The number you entered was positive.\n");
  else if (ques8(param1) == -1)
    printf("The number you entered was negative\n");
  else 
    printf("You entered 0.\n");
   
  if (ans8(param1) == 1)
    printf("The number you entered was positive\n");
  else if(ans8(param1) == -1)
    printf("The number you entered was negative\n");
  else 
    printf("You entered 0.\n");
  
  //Question 9
  printf("Enter three integers: ");
  scanf("%d %d %d", &param1, &param2, &param3);
  printf("\nques9(%d, %d, %d) replaces byte %d in %d with the 0 byte in %d, giving %d\n", param1,param2,param3,param2,param1,param3,ques9(param1,param2,param3));
  printf("ans9(%d, %d, %d) replaces byte %d in %d with the 0 byte in %d, giving %d\n", param1,param2,param3,param2,param1,param3,ans9(param1,param2,param3));

  //Question 10
  printf("Enter a number: \n");
  scanf("%d", &param1);
  printf("Ques10 always returns 0, Ques10(%d) = %d\n", param1, ques10(param1));
  printf("Ans10 always returns 0, Ans10(%d) = %d\n", param1, ans10(param1));

  //Question 11
  printf("Enter two numbers to be manipulated: \n");
  scanf("%d %d", &param1, &param2);
  
  if(ques11(param1, param2) == 1){
    printf("Your operation returned a positive output\n");
  }
  else{
    printf("Your operation returned negative output\n");
  }
  if(ans11(param1, param2) == 1){
    printf("Your operation returned a positive output\n");
  }
  else{
    printf("Your operation returned negative output\n");
  }


  //Question 12
  printf("Enter 3 integers: \n");
  scanf("%d %d %d", &param1, &param2, &param3);
  printf("Ques12(%d, %d, %d) determines whether %d is between %d and %d: %d\n", param1, param2, param3, param1, param2, param3,ques12(param1, param2, param3));
  printf("Ans12(%d, %d, %d) also determines whether %d is between %d and %d: %d\n", param1, param2, param3,param1, param2, param3,ans12(param1, param2, param3));

  //Question 13
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);
  printf("Ques13 returns the number of ones in the binary string: %d\n", ques13(param1));
  printf("Ans13 returns the number of ones in the binary string:  %d\n", ans13(param1));

  //Question 14
  printf("Enter a number to be manipulated: \n");
  scanf("%d", &param1);

  if (ques14(param1) == 1){
    printf("There is an odd number of 1's in the string.\n");
  }
  else{
    printf("There is an even number of 1's in the string.\n");
  }
  if (ans14(param1) == 1){
    printf("There is an odd number of 1's in the string.\n");
  }
  else{
    printf("There is an even number of 1's in the string.\n");
  }

  //Question 15
  printf("Enter two integers: \n");
  scanf("%d %d", &param1, &param2);
  printf("Ques15(%d, %d) returns the remainder when dividing %d by 2^%d: %d\n", param1, param2,param1, param2,ques15(param1, param2));
  printf("Ans15(%d, %d) returns the remainder when dividing %d by 2^%d: %d\n", param1, param2,param1, param2,ans15(param1, param2));

}



