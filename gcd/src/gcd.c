#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int num0, long long int num1);    // declaration of the function that will be used

int main(int argc, char * argv[]){              // argc and argv is used to read arguments from the command line
                                                // argc reads the amount of arguments while argv reads the string of the arguments 
    long long int final;                        
    if (argc!=3){                               // check for correct amount of arguments
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }
    long long num0 = atoll(argv[1]);            // change the string to a long long int 
    long long num1 = atoll(argv[2]);            // change the string to a long long int
    //checks if any of the too numbers is 0 so that it ends with an exit code of 1
    if (num0==0){                               
        return 1;
    }
    if (num1==0){
        return 1;
    }
    // calls the function and returns the result to the veriable final 
    final = gcd(num0,num1);
    printf("gcd(%lld,%lld) = %lld\n", num0,num1,final);     // prints the correct answer 
    return 0;
}


long long int gcd(long long int num0, long long int num1){ 
    // checks and turns all numbers to positive so that it can find the GCD accuretly         
    if (num0<0){                   
        num0 = num0 * (-1);
    }
    if (num1<0){
        num1 = num1 * (-1);
    }
    // finds with the help of the Euclidean Algorithm the GCD 
    if (num0 % num1 == 0){
        return num1;            // returns the correct answer
    } else {
        return gcd(num1,num0 % num1);       // calls again the same funcion with diffrent argumets until it finds the GCD
    }
}