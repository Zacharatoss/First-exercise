#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime_check(long long int number);
long long int gcd(long long int e, long long int phiN);
long long int module(long long int m,long long int exp,long long int N);

int main(int argc, char * argv[]){
    long long int N,message,phip,phiq,m,phiN;
    // check for correct amount of arguments 
    if (argc!=6){
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
        return 1;
    }
    // check for correct syntax of the first argument
     char *ch = argv[1];                        
    if (strcmp(ch, "enc") != 0 && strcmp(ch, "dec") != 0){   
        printf("First argument must be 'enc' or 'dec'\n");
        return 1;
    }
    // chenges all of the rest arguments into numbers 
    long long int e = atoll(argv[2]);
    long long int d = atoll(argv[3]);
    long long int p = atoll(argv[4]);
    long long int q = atoll(argv[5]);
    // checks for any negative numbers
    if (e<0 || d<0 || p<0 || q<0){
        printf("Negative numbers are not allowed\n");
        return 1;
    }
    // checks if p and q are prime 
    if (prime_check(p)==1 || prime_check(q)==1){ // uses the function prime_check that returns how many times the number can be divited and because prime   
        printf("p and q must be prime\n");      // numbers can only be divided with them selfes and 1 if the number that is reterund is not 2 then its not prime
        return 1;
    }
    // because p and q are prime by using the totient function we find the coprime of p and q
    phip = p-1;
    phiq = q-1;
    phiN = phip * phiq;     // phiN is the amount of coprimes of p and q
    // checks if e is not coprime with phi(N)
    if (gcd(e,phiN)!=1){             // using the function gcd if the gcd is 1 then e is coprime with phiN 
        printf("e is not coprime with phi(N)\n");
        return 1;
    }
    // checks if e and d are reversable 
    if (e * d % phiN != 1){                 // this (e * d % phiN) is the way to see if e and d are reversable
        printf("e * d mod phi(N) is not 1\n");
        return 1;
    }
    N = p*q;
    message = scanf("%lld", &m);     //reads the message that will be encupted or decrupted 
    // checks if only 1 number was read      
    if (message!=1){
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
        return 1;
    }
    // ckecks if the massege is a negative number
    if (m<0){
        printf("Negative numbers are not allowed\n");
        return 1;
    }
    // ckecks if message is larger than N
    if (m>= N){
        printf("Message is larger than N\n");
        return 1;
    }
    if ( strcmp(ch, "enc")==0){
        module(m,e,N);
    } else {
        module(m,d,N);
    }
}


int prime_check(long long int number){        
    long long int rem;
    int i=2,ans=0;
    while (i<= number/2){
        rem = number % i;
        if (rem != 0){
            i++;
        }else {
            ans=1;
            return ans;
        }
    }
    return ans;
}

long long int gcd(long long int e, long long int phiN){ 
    // finds with the help of the Euclidean Algorithm the GCD 
    if (e % phiN == 0){
        return phiN;            // returns the correct answer
    } else {
        return gcd(phiN,e % phiN);       // calls again the same funcion with diffrent argumets until it finds the GCD
    }
}

long long int module(long long int m,long long int exp,long long int N){
    long long int result;
    result = 1;
    m = m % N;
    while (exp>0){
        if (exp % 2 == 1){
            result = (result * m) % N;
        }
        m = (m*m) % N;
        exp = exp/2;
    }
    printf("%lld\n", result);
    return 0;
}