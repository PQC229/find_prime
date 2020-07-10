This c++ code is to find a large-number prime of 2^(x)3^(2y)+/-1 using the brute-force search.
The prime property is verified by using the GMP function: mpz_probab_prime_p. The explanation for it can be found in https://gmplib.org/manual/Number-Theoretic-Functions.
 
Function: int mpz_probab_prime_p (const mpz_t n, int reps)
Determine whether n is prime. Return 2 if n is definitely prime, return 1 if n is probably prime (without being certain), or return 0 if n is definitely non-prime.

This function performs some trial divisions, a Baillie-PSW probable prime test, then reps-24 Miller-Rabin probabilistic primality tests. A higher reps value will reduce the chances of a non-prime being identified as “probably prime”. A composite number will be identified as a prime with an asymptotic probability of less than 4^(-reps). Reasonable values of reps are between 15 and 50.

reps is set to 50 in our experiment.

How to run:
1. install the GMP in your Linux system
2. g++ find_prime.cpp -o find_prime -lgmpxx -lgmp
3. ./find_prime 