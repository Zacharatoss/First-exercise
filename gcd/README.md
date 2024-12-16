## Project description 

This project can read from the command line 2 numbers and fine the GCD (Greatest Common Divisor) between the two numbers using the Euclidean Algorithm. [Euclidean Algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)

If either of the numbers is 0 or there is a false input of numbers the program will end with an exit code of 1 else it will have an exit code of 0.  

## Usage 

To use the project compile it with the following command:

     gcc -O3 -Wall -Wextra -Werror -pedantic -o gcd gcd.c

Then you can enter the numbers you what to find the GCD with the command: 

    ./gcd num0 num1


## Examples 

    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$ gcc -O3 -Wall -Wextra -Werror -pedantic -o gcd gcd.c
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd
    Usage: ./gcd <num1> <num2>
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$ echo $?
    1
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd 1
    Usage: ./gcd <num1> <num2>
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd 18 42
    gcd(18,42) = 6
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd 42 18
    gcd(42,18) = 6
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd -42 18
    gcd(-42,18) = 6
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd 982451653 776531401
    gcd(982451653,776531401) = 1
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  ./gcd 68719476736 84767329979727872
    gcd(68719476736,84767329979727872) = 68719476736
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$ echo $?
    0
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$ ./gcd 654125425 365450
    gcd(654125425,365450) = 25
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$ ./gcd 42 42
    gcd(42,42) = 42


## Time

    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$  time ./gcd 1000000000000000000 999999999999999999
    gcd(1000000000000000000,999999999999999999) = 1

    real    0m0,015s
    user    0m0,012s
    sys     0m0,004s
    sdi2400048@linux12:~/hw1-Zacharatoss/gcd/src$ time ./gcd 654125425 365450
    gcd(654125425,365450) = 25

    real    0m0,016s
    user    0m0,007s
    sys     0m0,011s


## Test folder 

In the test folder there are two files <input.txt> and <output.txt>. In the <input.txt> there are two random numbers that can be used as an input to the program. In the <output.txt> is plased the Greatest Common Divisor of the numbers that are in the <input.txt> file.