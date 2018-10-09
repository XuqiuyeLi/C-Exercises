#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
     Write a main program that does all the following.  I suggest,
     but do not require, that you use getint() from the notes and
     given on page 97 of the book.

     * Reads a positive integer N.
     * Checks that 0<N<100.  If N is not in that range, prints
         an error message and terminates.
     *  Assuming N is legal
      i.   Reads N more integers into an array.
     ii.  Prints the contents of the array, one number per line.
     iii. Calls your sort routine from part A.
     iv.  Prints the sorted array, one number per line.
*/
int getch(void);
void ungetch(int);


int getint(int *pn) {
    int c, sign;
    while (isspace(c=getch())) ;
    if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
      ungetch(c);
      return 0;
    }
    sign = (c=='-') ? -1 : 1;
    if (c=='+' || c=='-')
      c = getch();
    for (*pn = 0; isdigit(c); c=getch())
      *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if (c != EOF)
      ungetch(c);
    return c;
 }

int main (){
	int i = getint();
	//int j = 0;
	//int A[i]; 
	if(i <= 0 || i >= 100){
		printf("The integer is not between 0 and 100."); 
		return 0;
	}
	printf("%d\n", i);
	/*while(i > 0){
		A[j] = getchar();
		printf("%d\n", A[j]);
		j++;
		i--;
	}
	sortInt(i, A);
	for(j = 0; j < i; j++) {
		printf("%d\n", A[j]);
	}*/
	return 0;

}