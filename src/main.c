#include <stdio.h>
#include <stdlib.h>
#include <cliparse/cliparse.h>


int main(int argc, char *argv[]) {
  float k = cliparse_get_arg_float(argc, argv, "--test");
  printf("%12.6f\n", k);
  return 0;
}
