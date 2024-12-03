#### Project description

This project can read 5 arguments from the command line as well as a message and it can either encrypt the message or decrypt it.


It uses 3 functions:
- Prime_check 
 
  This function gets a number as an input and divides with all the numbers that are possible to be divited witch is number/2. If it finds any number that can divide our number, then our number it not prime and the function returns a value of 1.
  [Prime_code](https://www.educative.io/courses/introduction-to-computers-and-programming/determine-if-a-number-is-prime#Pseudocode) 

- GCD 
 
  This function gets 2 numbers and finds the GCD (Greatest Common Divisor) between the two numbers using the [Euclidean_Algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)

- module 

  This function depending on the first argument ("enc" or "dec") can encrypt a message by passing to the function the message (m), N which is the modulo and e to the veriable exp or decrypt a message by passing to the function the message (m), N which is the modulo and d to the veriable exp. This function is bases to the [Modular_exponentiation](https://en.wikipedia.org/wiki/Modular_exponentiation) which is uses to calculate the power of really big numbers and it is uses for the encryption and decryption  


#### Usage
 
To run the program firstly you will have to compile it: 
```gcc -O3 -Wall -Wextra -Werror -pedantic -o rsa rsa.c```

When the program is compiled to use it follow the following syntax: 
```echo <message> | ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>```

