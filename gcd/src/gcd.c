#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int num0, long long int num1);

int main(int argc, char * argv[]){
    long long int final;
    if (argc!=3){
        printf("Usage: ./gcd <num1> <num2>\n");
        return 1;
    }
    long long num0 = atoll(argv[1]);
    long long num1 = atoll(argv[2]);
    final = gcd(num0,num1);
    printf("gcd(%lld,%lld) = %lld\n", num0,num1,final);
    return 0;
}


long long int gcd(long long int num0, long long int num1){
        if (num0<0){
        num0 = num0 * (-1);
    }
    if (num1<0){
        num1 = num1 * (-1);
    }
    if (num0 % num1 == 0){
        return num1;
    } else {
        return gcd(num1,num0 % num1);
    }
}