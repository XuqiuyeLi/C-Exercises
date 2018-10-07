/*
	Write a main program that reads characters from the terminal and
    writes characters on the screen.  Your program must use getchar()
    to read and putchar() to write.

    If the character read is not a letter, it is printed unchanged.

    If the character is an upper case letter, print the letter in
    lower case.

    If the character is a lower case letter, print the letter in
    upper case. */
#include <stdio.h>
#include <ctype.h>

	
	int main(){
		int c;
		while((c = getchar())!= EOF){
			// if not a letter
			if(!isalpha(c)){
				putchar(c);
			}
			// if upper case letter
			if(c >= 'A' && c <= 'Z') {
				putchar(tolower(c));
			}
			// if lower case letter
			if(c >= 'a' && c <= 'z'){
				putchar(toupper(c));
			}
		}
		return 0;
	}