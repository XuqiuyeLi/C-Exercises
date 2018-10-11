#include <stdio.h>
#include <stdlib.h>

/* 
 * @author Summer Li
 * 
 * A (10 Points)
 * This function sorts the array A of integers.
 */

int compare (const void * a, const void * b) {
	// sort int in ascending order
	return ( *(int*)a - *(int*)b );
}

void sortInt(int n, int A[n]) {
	// built-in function for sorting array 
	// here, A is the pointer to the first element of the array to be sorted.
	qsort(A, n, sizeof(int), compare);
}




/*
B (10 Points)
     * Reads a positive integer N.
     * Checks that 0<N<100.  If N is not in that range, prints
         an error message and terminates.
     *  Assuming N is legal
      i.   Reads N more integers into an array.
     ii.  Prints the contents of the array, one number per line.
     iii. Calls your sort routine from part A.
     iv.  Prints the sorted array, one number per line.
*/



int main(){
    int i = 0;
    int number;
    int n;
    printf("Enter an integer: ");   
    // scanf() reads the formatted input and stores them
    scanf("%d", &number);
    n = number;

    if(n > 0 && n < 100){
      int A[n];
      printf("\nThe sorting function only works if you enter numbers!\nPlease enter %d integers:\n", n); 
      while(n > 0){  
        scanf("%d", &A[i]);
        n--;
        i++;
      }
      // prints the original array
      printf("\n\nThe original array is:\n");
      for(i = 0; i < number; i++){
        printf("%d\n", A[i]);
      }
      // call the sort function to sort numbers in ascending order
      sortInt(number,A);
      // prints the sorted array
      printf("\n\nThe sorted array is:\n");
      for(i = 0; i < number; i++){
        printf("%d\n", A[i]);
      }
    }
    else{
      // N <= 0 or N >= 100
      printf("The integer is not valid! Please try integer between 0 and 100.\n"); 
      return 0;
    }  
    return 0;
}
