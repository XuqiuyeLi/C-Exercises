#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* 
 * @author Summer Li
 * Write a program that converts upper case to lower or lower case to upper, 
 * depending on the name it is invoked with, as found in argv[0]
 */


int main(int argc, char * argv[]) {
	int result;
	int input = atoi(argv[0]); 
	if(input == 'upper') {
		result = toupper(input);
		return result;
	}
	if(input == 'lower') {
		result = tolower(input);
		return result;
	}
	printf("Invalid argument");
	return 0;
}