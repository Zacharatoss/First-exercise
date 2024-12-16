#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  long long int num1 = 0, num2, i;
  // check for correct amount of arguments
  if (argc != 2) {
    printf("Usage: %s <semiprime>\n", argv[0]);
    return 1;
  }
  long long int sem = atoll(argv[1]);  // chenges the argument into a number
  // by using the square root function we minimize the numbers that will be
  // checked
  for (i = 2; i <= sqrt(sem); i++) {
    if (sem % i ==
        0) {     // if it finds a number that can divide sem then the loop ends
      num1 = i;  // stores the number that can divide our number in the veriable
                 // num1
      break;
    }
  }
  num2 = sem / num1;  // dividing our starting number with num1 with find the
                      // second number that can divide our number
  printf("Factors: %lld %lld\n", num1,
         num2);  // prints the two numbers that are the factors
  return 0;
}