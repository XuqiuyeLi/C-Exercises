#include <stdio.h>
#include <stdlib.h>
/* 
 * @author Summer Li
 * 
 * A (15 Points)
 * This function checks if a number is prime or not
 */

// Assume the input is number
int isPrime(int x) {
    // If x<2 or x>1000, the input is erroneous and isPrime() returns -1.
	if( x < 2 || x > 1000) {
		return -1;
	}
    // If 2<=x<=1000 and x is not a prime number, isPrime() returns 0.
	// check if x is divided by any natural number starting from 2 until x/2
	for(int i = 2; i <= x / 2; i++) {
		// if x can be divided by a smaller natural number, then it's not prime
		if( x % i == 0){
			return 0;
		}
	}
    // If 2<=x<=1000 and x is a prime number, isPrime() returns 1.
	return 1;
}





/*
 * B (10 Points)
 * This programs takes two arguments lo, hi and calls isPrime(x) for each lo <= x <= hi.
 * For each x, main() prints one line which states either
 *       x is invalid
 *       x is prime
 *       x is not prime
 */

int main(int argc, char * argv[]) {
	int lo = atoi(argv[1]); 
	int hi = atoi(argv[2]);
	// check if right numbers of argumnents are passed in
	if(argc == 3){
		if(lo > hi){
			printf("The first argument should be smaller than the second!\n");
			return 0;
		}
		// assume lo <= hi
		for(int i = lo; i <= hi; i++){
			if(isPrime(i) == 1){
				printf("%d is prime\n", i);
			}
			else if(isPrime(i) == 0){
				printf("%d is not prime\n", i);
			}
			else{
				printf("%d is invalid\n", i);
			}
		}
	}
	return 0;
}

