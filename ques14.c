int ques14(int x) {
  
  int result = 0;
  int i;

  for (i = 0; i < 32; i++)
   result ^=  (x >> i) & 0x1;

   return result;
}
