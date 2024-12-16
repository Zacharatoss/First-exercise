## Description 

This program takes from the command line one semiprime number and can find the two factors of that number. 



A natural number is called semiprime when it is the product of exactly two prime numbers. For example, the number 46 is semiprime (2 * 23), as is the number 9 (3 * 3). On the other hand, the number 42 is not semiprime. [Semiprimes](https://en.wikipedia.org/wiki/Semiprime)


## Usage 

To run the program firstly you will have to compile it:

    gcc -O3 -Wall -Wextra -Werror -o factor factor.c -lm

and then 

    ./factor <semiprime>

where in semiprime you put in a semiprime number.

## Examples 

    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$  ./factor
    Usage: ./factor <semiprime>
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$ echo $?
    1
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$  ./factor 93
    Factors: 3 31
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$ echo $?
    0
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$ ./factor 9827348119
    Factors: 613 16031563
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$  ./factor 2524891914334062643
    Factors: 1175747593 2147477851

## Time 

    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$ time ./factor 9827348119
    Factors: 613 16031563

    real    0m0,005s
    user    0m0,004s
    sys     0m0,001s
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$ time  ./factor 2524891914334062643
    Factors: 1175747593 2147477851

    real    0m9,329s
    user    0m9,327s
    sys     0m0,001s
    sdi2400048@linux12:~/hw1-Zacharatoss/factor/src$