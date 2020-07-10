/******
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

Authors: Jing Tian 
Organization: Nanjing University
Time: 26/06/2020
******/
#include<iostream>
#include<gmpxx.h>
using namespace std;
int main()
{
mpz_t num,num1,num2, num3, num4, num5;
mpz_init(num);
mpz_init(num1);
mpz_init(num2);
mpz_init(num3);
mpz_init(num4);
mpz_init(num5);

//num = "7";
//num = "69364773003258908579746377758190421978976381649320029237528520059299811360727";
int i;
int j, k=0;
int l;
int f1, f2, f3, f4;
size_t size1, size2, size3, size4;

int N=200, M=100, K=100; //can be changed for different security level.

for(i=N;i<N+K;i++)
    for(j=M;j<M+K;j=j+2)
    {
    mpz_ui_pow_ui(num1,2,i);
    mpz_ui_pow_ui(num2,3,j);
    mpz_mul(num,num1,num2);
	size1 = mpz_sizeinbase(num1, 2);
	size2 = mpz_sizeinbase(num2, 2);
	f3 = abs((int)size1 - (int)size2);
	if (f3>10)
		continue;
	mpz_sub_ui(num4,num,1);
	mpz_add_ui(num5,num,1);
    f1 = mpz_probab_prime_p(num4,50);
	f2 = mpz_probab_prime_p(num5,50);
    if((f1 == 1) || (f1 == 2))
    {
		cout << "-1:" << endl;
		cout << dec << i << endl;
		cout << dec << j << endl;
		cout << hex << num4 << endl;
		k++;
		cout << dec << f3 << endl;
		size3 = mpz_sizeinbase(num4, 2);
		l = (int)size3;
		cout << dec <<"log2(p) = "<< l << endl;
	}
	if((f2 == 1) || (f2 == 2))
    {
		cout << "+1:" << endl;
		cout << dec << i << endl;
		cout << dec << j << endl;
		cout << hex << num5 << endl;
		k++;
		cout << dec << f3 << endl;
		size4 = mpz_sizeinbase(num5, 2);
		l = (int)size4;
		cout << dec <<"log2(p) = "<< l << endl;
	}
	
}
cout << dec << k << endl;
}