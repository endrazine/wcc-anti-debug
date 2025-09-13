// Adapted from https://github.com/JonathanSalwan/binary-samples/blob/master/anti-disassembler/Linux/anti-debug/anti-ptrace.c

#include <stdio.h>
#include <stdlib.h>

#include <sys/ptrace.h>

int
main ()
{
  if (ptrace (PTRACE_TRACEME, 0, 1, 0) == -1)
    {
      printf ("don't trace me !!\n");
      printf ("FAILED\n");
      exit (EXIT_FAILURE);
    }

  printf ("PASS\n");
  return EXIT_SUCCESS;
}
