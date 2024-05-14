#include "zipcode_data.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  load_file(argv[1]);
  int zipcode;
  int count;
  for (int i = 2; i < argc; i++) {
    zipcode = strtol(argv[i], (char **)NULL, 10);
    count = count_orders(zipcode);
    printf("%i\n", count);
  }
  return 0;
}
