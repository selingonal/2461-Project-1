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
