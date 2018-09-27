#include <stdio.h>

/*
 * @author Summer Li
 * sets A to the old value of B, sets B to old C, and C to old A.
 */
void rotate3(A,B,C){
	// let pointer p stores the address of A variable
	void *p = &A; 
	A = B;
	B = C;
	// set C to the value of p
	C = *p;
	// end of the program
	return 0;
}