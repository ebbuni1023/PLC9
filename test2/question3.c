/**
Name:Jiyoung Yoon

CITATION:
Roussell, Michael April 2021

Explanation of Code:
Also just like with anything make sure to comment the hell out of your code
*/

#include <stdio.h>
#include "time.h"
int main(void) {
  // reference to elements of two-dimensione arrays
  int arr[100][100];
  // pointer arithmetic for the storage-mapping function to do the array references
  int *ptr = &arr[0][0];

  int i, j;
  clock_t start, stop;
  clock_t start1, stop1;

  // start the clock
  start = clock();
  for(i = 0; i< 100;i++){
    for(j = 0; j< 100;j++){
      arr[i][j] = i + j;
    }    
  }
  // stop the clock
  stop = clock();

  // calculating the time elapsed in array references
  printf("%ld\n", stop - start);
  // start the clock
  start1 = clock();
  for(i = 0; i< 100 * 100;i++){
       *(ptr + i) = 0;
  }
  // stop the clock
  stop1 = clock();
  // calculating the time elapsed in two-dimensioned arrays
  printf("%ld\n", (stop1- start1));
  return 0;
}