//*file: RSA*//
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
        printf("Usage: %s enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n", argv[0]);
        return 1;
    }
        // check for correct syntax of the first argument                        
    if (strcmp(argv[1], "enc") != 0 && strcmp(argv[1], "dec") != 0){   
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
    if (prime_check(p)==1 || prime_check(q)==1){    // uses the function prime_check that returns 1 if the number is not prime and 0 if the number is prime   
        printf("p and q must be prime\n");      
        return 1;
    }
        // because p and q are prime by using the totient function we find the coprime of p and q
    phip = p-1;
    phiq = q-1;
    phiN = phip * phiq;      // phiN is the amount of coprimes of p and q
        // checks if e is not coprime with phi(N)
    if (gcd(e,phiN)!=1){    // using the function gcd if the gcd is 1 then e is coprime with phiN 
        printf("e is not coprime with phi(N)\n");
        return 1;
    }
        // checks if e and d are reversable 
    if (e * d % phiN != 1){     // this (e * d % phiN) is the way to see if e and d are reversable
        printf("e * d mod phi(N) is not 1\n");
        return 1;
    }
    N = p*q;   
    message = scanf("%lld", &m);        //reads the message that will be encupted or decrupted 
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

    if ( strcmp(argv[1], "enc")==0){
        module(m,e,N);      //if the argument is "enc" then we pass through the function the correct veriables so that it can encrypt the message
    } else {
        module(m,d,N);      //if the argument is "dec" then we pass through the function the correct veriables so that it can decrypt the message
    }
}

//checks to find if the numbers are prime
int prime_check(long long int number){          
    int i=2;
    int flag=0;     // if flag remains with the value of 0 then the number is prime      
    while (i<= number/2){   //checks all the possible numbers that can divide the number that we are checking      
        if (number % i != 0){   //ckecks if the number can be divited 
            i++;        //adds +1 to i because i couldn't divide our number
        }else {
            flag=1;     // if it finds an i that can divide our number that means our number is not prime and flag takes the value of 1
            return flag;    // and ends the function
        }
    }
    return flag;        // if it doesn't find an i that can divide our number the function returns the flag with value 0
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
    // using the Modular exponentiation algorithm to find the encrypted or deprypted code
    long long int result;
    result = 1;
    m = m % N;      // to prevent overflow we use the module 
    while (exp>0){
        if (exp % 2 == 1){      // if the exp is odd we multiply the result by m
            result = (result * m) % N;
        }
        m = (m*m) % N;      // we square m and take the modulo
        exp = exp/2;        // we reduse the exp by half
    }
    printf("%lld\n", result);
    return 0;
}