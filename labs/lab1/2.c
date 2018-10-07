/*
B (10 Points)
     Write a main program that takes two command-line arguments,
     lo and hi.

     If lo > hi main() prints an appropriate error message and terminates.

     Assuming lo <= hi, main() calls isPrime(x) for each lo <= x <= hi.
     For each x, main() prints one line which states either
         x is invalid
         x is prime
         x is not prime
     (You don't print a literal x but instead the value of x). */


void main(int lo, int hi) {
	// assume lo <= hi
	if(lo > hi){
		return -1;
	}
	for(int i = lo; i < hi; i++){
		if(isPrime(i) == 1){
			printf("%d is prime", i);
		}
		if(isPrime(i) == 0){
			printf("%d is not prime", i);
		}
		else{
			printf("%d is invalid", i);
		}
	}
}


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



