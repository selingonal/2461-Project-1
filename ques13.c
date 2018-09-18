int ques13(int x) {

    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8); // decimal: 51 + 13056 = 13107 
    mask2 += mask2 << 16; // decimal: 13107 + 858980352 = 858993459 
    mask1 = mask2 ^ (mask2 << 1); // mask1: 1010101010101010101010101010101 (string of alternating 1s and 0s) 
    mask4 = 0x0F + (0x0F << 8); //decimal: 15 + 3840 = 3855
    mask4 += mask4 << 16; // mask4: 3855 + 252641280 = 252645135
    mask8 = 0xFF + (0xFF << 16); // mask8: 255 + 16711680 = 16711935
    mask16 = 0xFF + (0xFF << 8); // mask16: 255 + 65280 = 65535

    //string manipulation to end up with the number of 1's in the binary representation of the original input 
    x = (x & mask1) + ((x >> 1) & mask1); 
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);
    
    return x; // counter for number of 1's in binary representation of a number x 
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
}
