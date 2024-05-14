#define DATA_LENGTH 10000000

#include "zipcode_data.h"
#include <stdio.h>

int data[DATA_LENGTH];


int count_orders(int zipcode) {
  int count = 0;
  for (int i = 0; i < DATA_LENGTH; i++) {
    if (data[i] == zipcode) {
      count++;
    }
  }
  return count;
}


void load_file(const char *name) {
  FILE *fptr = fopen(name, "r");
  int zipcode;
  for (int i; fscanf(fptr, "%i[\n]", &zipcode) == 1; i++) {
    data[i] = zipcode;
  }
}
