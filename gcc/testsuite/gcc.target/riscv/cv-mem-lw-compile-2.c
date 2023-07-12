/* { dg-do compile } */
/* { dg-options "-march=rv32i_xcvmem -mabi=ilp32 -fno-unroll-loops" } */
/* { dg-skip-if "" { *-*-* }  { "-O0" } { "" } } */

int fooSIsigned (signed int* array_int, int n, int j)
{
  int int_sum = 1;

  for(int i=0; i<n; i+=j)
  {
    int_sum += array_int[i];
  }

  return int_sum;
}

/* { dg-final { scan-assembler-times "cv\\.lw\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),4\\(\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\)\\!\\)" 2 } } */
