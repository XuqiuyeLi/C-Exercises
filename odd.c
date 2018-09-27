#include <stdio.h>

/* 
 * @author Summer Li
 * Write a C funcion int odd (int x) that returns 1 if x is odd and 
 * returns 0 if x is even. 
 */

int odd(int x){
  	// odd
   if(x % 2 == 1){
   	 return 1;
   }
   // even
   else{
   	 return 0;
   }
}

// without if
int odd(int x){
	// if the statement is true, return 1, else, return 0
	return (x % 2 == 1 ? 1 : 0);
}