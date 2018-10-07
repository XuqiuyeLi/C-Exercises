/*
 * @author Summer Li
 * A main program that reads characters from the terminal and
 * writes characters on the screen. 
 */

#include <stdio.h>
#include <ctype.h>

	
	int main(){
		int c;
		while((c = getchar())!= EOF){
			// if not a letter, print as it is
			if(!isalpha(c)){
				putchar(c);
			}
			// if upper case letter, print as lower case
			if(c >= 'A' && c <= 'Z') {
				putchar(tolower(c));
			}
			// if lower case letter, print as upper case
			if(c >= 'a' && c <= 'z'){
				putchar(toupper(c));
			}
		}
		return 0;
	}