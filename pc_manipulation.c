// Adapted from: https://github.com/JonathanSalwan/binary-samples/blob/master/anti-disassembler/Linux/pc_manipulation/pc_manipulation-amd64.c

#include <stdio.h>
#include <stdint.h>

int foo (void) {
  char buffer[8];
  char * ret;
  ret = buffer + 24;
  (*ret) += 7;
  return 0;
}

int main (void) {
  int i = 42;
  foo ();
  i = 1;
  printf ("%d\n", i);
  if (i == 42) {
      printf ("PASS\n");
  } else {
      printf ("FAILED\n");
  }  

  return 0;
}

