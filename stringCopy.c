#include <stdio.h>
#include <string.h>


char *strncpy(char *s, char *t, int n){
	int count = 0;
	while( *s++ = *t++ && count < n ){
		count++;
	}
	return s;
}