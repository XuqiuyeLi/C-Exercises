#include <stdio.h>


/*
 * Converts the characters newline and tab into two character sequences \n and \t 
 * as it copies the string t to the string s.
 */
char escape(char s[], char t[]){
	int i;
	int size = sizeof(t)/sizeof(char);
	for(i=0; i < size;i++){
		// print out the newline and tab characters
		switch(t[i]){
			case '\n':
				s[i] = '\\n';
				break;
			case '\t':
				s[i] = '\\t';
				break;
			default:
				s[i] = t[i];
		}
	}
	return s;
}



/*
 * Converts character sequences \n and \t to newline and tab
 * as it copies the string t to the string s.
 */
char unescape(char s[], char t[]){
	int i;
	int size = sizeof(t)/sizeof(char);
	for(i=0; i < size;i++){
		// reverse the newline and tab characters to newline and tab
		switch(t[i]){
			case '\\n':
				s[i] = '\n';
				break;
			case '\\t':
				s[i] = '\t';
				break;
			default:
				s[i] = t[i];
		}
	}
	return s;
}