#include <stdio.h>
#include <stdlib.h>
int prime_check(long long int number);

int main(int argc, char * argv[]){


    if (argc!=6){
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
        return 1;
    }
    char c = argv[1][2];                            
    if ( argv[1] != "dec" || argv[1] !="enc"){
        printf("First argument must be 'enc' or 'dec'\n");
        return 1;
    }
    long long int e = atoll(argv[2]);
    long long int d = atoll(argv[3]);
    long long int p = atoll(argv[4]);
    long long int q = atoll(argv[5]);
    if (e<0 || d<0 || p<0 || q<0){
        printf("Negative numbers are not allowed\n");
    }
    if (prime_check(p)!=2 || prime_check(q)!=2){
        printf("p and q must be prime\n");
        return 1;
    }
    return 0;
}



int prime_check(long long int number){
    long long int times=0;
    for(int i=1;i<=number;i++){
        if(number % i == 0){
            times++;
        }
    }
    return times;
}