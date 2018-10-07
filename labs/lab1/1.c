/*
  Write a main program that has three command line arguments called
     start, end, and incr.  All three are integers.
     Your program prints a series of numbers
        start, start+incr, start+(2*incr), ..., end
     For example, if the three arguments are 2, 10, and 3, the values
     printed are 2, 5, 8, 10.
     Note from the example that the end value is printed even if it is
     not of the form start plus a multiple of incr.

     You may assume for problem 1 that the arguments are legal, i.e.,
     start<end and incr>0. */



     int main(int start, int end, int incr) {
     	for(int i = start; i < end; i += incr) {
     		printf("%d", i);
     	}
     	printf("%d", end);
     }