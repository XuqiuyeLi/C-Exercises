#include <stdio.h>

/*
 * @author Summer Li
 * Sets x to old x + old y and sets y to old x - old y.
 */
int plusminus(int x,int y){
	int temp = x;
	x = x + y;
	// the x is changed already, so we use temp here as old x
	y = temp - y;
	return 0;
}