/* 
A (15 Points)
     Write the following C function

int isPrime(int x) {
   // If x<2 or x>1000, the input is erroneous and isPrime() returns -1.
   // If 2<=x<=1000 and x is a prime number, isPrime() returns 1.
   // If 2<=x<=1000 and x is not a prime number, isPrime() returns 0.
}

*/


int isPrime(int x) {
    // If x<2 or x>1000, the input is erroneous and isPrime() returns -1.
	if( x < 2 || x > 1000) {
		return -1;
	}
    // If 2<=x<=1000 and x is a prime number, isPrime() returns 1.
	// check if x is divided by any natural number starting from 2 until x/2
	for(int i = 2; i <= x / 2; i++) {
		// if x can be divided by a smaller natural number, then it's prime
		if( x % i == 0){
			return 1;
		}
	}
    // If 2<=x<=1000 and x is not a prime number, isPrime() returns 0.
	return 0;
}