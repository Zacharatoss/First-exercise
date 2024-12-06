#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
  long long int num1=0,num2,i;
  if (argc != 2) {
    printf("Usage: ./factor <semiprime>\n");
    return 1;
  }
long long sem = atoll(argv[1]);
for (i=2;i<=sqrt(sem);i++){
    if (sem % i ==0){
      num1 = i;
      break;
    }
}
num2 = sem/num1;
printf("Factors: %lld %lld\n", num1,num2);
return 0;
}