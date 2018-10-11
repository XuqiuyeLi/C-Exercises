/*
 * @author Summer Li
 */

#include <stdio.h>
#include <stdlib.h>

     int main(int argc, char * argv[]) {
        // Converting string type to integer type
        // only takes 3 numbers as arguments
        if(argc == 4) {
            // argv[0] is the program name arg
            int start = atoi(argv[1]); 
            int end = atoi(argv[2]);
            int incr = atoi(argv[3]);
            int i;
            for(i = start; i < end; i += incr) {
                printf("%d\n", i);
            }
            printf("%d\n", end);
        }
        return 0;
    }
