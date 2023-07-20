/* { dg-do compile } */
/* { dg-options "-march=rv32i_xcvmem -mabi=ilp32 -fno-unroll-loops" } */
/* { dg-skip-if "" { *-*-* }  { "-O0" "-Os" "-Og" "-Oz" } { "" } } */

int fooSIsigned (signed int* array_int, int n, int j)
{
  int int_sum = 1;

  for(int i=0; i<n; i+=j)
  {
    array_int[i] += int_sum;
  }

  return int_sum;
}

int fooSIunsigned (unsigned int* array_uint, int n, int j)
{
  int uns_int_sum = 1;

  for(int i=0; i<n; i+=j)
  {
    array_uint[i] += uns_int_sum;
  }

  return uns_int_sum;
}

/* { dg-final { scan-assembler-times "cv\\.sw\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\)\\(\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\)\\!\\)" 2 } } */
