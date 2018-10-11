/*   Write a C main program that plays the following simplification of
     Conway's game of life.

     The program reads 10 integers from the terminal.
     The first integer is called numGen short for number of
     generations.  Check that it is positive and abort the run if it is
     not.  The remaining 9 integers must each be 0 or 1 (check that
     they are 0 or 1 and abort if not).
 */



#include <stdio.h>
/*
int readValidInt(int x){
     int y;
     if(x == 0 || x == 1){
          return 1;
     }
     else{
          scanf("%d", &y);
          return validInt(y);
     }
     return 0;
} */


/* 
 * This function takes a 3x3 matrix and print it
 */

void * printMatrix(int A[9]){
     int i;
     for(i = 0; i < 9; i++){
          if(i == 3 || i == 6){
               printf("\n");
          }
          printf("%d ", *(A+i));
     }    
     printf("\n\n");
     return 0;
}




/*
 * Returns a poniter to an array containing the number of "1" neighbors of a cell
 */
int * neighbor(int A[9]){
     int num = 0;
     int x = 0;
     int y = 0;
     int i, j;
     // Create a bigger matrix with the original surrounded by "0"
     int fiveAndfive[25] = {0,0,0,0,0,0,A[0],A[1],A[2],0,0,A[3],A[4],A[5],0,0,A[6],A[7],A[8],0,0,0,0,0,0};
     int neighborIndex[8] = {-6, -5, -4, -1, 1, 4, 5, 6};
     for(i = 6; i < 19 ; i++){
          // skip the border elements not from original matrix
          if(i!= 9 && i!= 10 && i!= 14 && i!= 15){
               for(j = 0; j < 8; j++){
                    x = i + neighborIndex[j];
                    // count the number of "1" of all neighbors
                    if(fiveAndfive[x] == 1){
                         num++;
                    }
                    // skip the neighbors that are 0
                    else{
                         continue;
                    }
               }
               // store the num of "1" neighbours in the array
               A[y] = num;
               y++;
          }
          // reset num to 0
          num = 0;
     }
     return A;
}

/*
 * This function takes a 3x3 matrix and returns a new matrix by following rule:
 * First,for each cell in generation 0, count how many of its neighbors
 * are 1.  If that count gives 2 or 3, the cell is 1 in next generation
 * If the count is neither 2 nor 3, the cell is 0 in next generation
 */
int * generateNewMatrix(int A[9]){
     int i;
     int *neighbors;
     neighbors = neighbor(A);
     for(i = 0; i < 9; i++){
          if(*(neighbors+i) == 2 || *(neighbors+i) == 3){
               A[i] = 1;
          }
          else{
               A[i] = 0;
          }
     }
     return A;
}


int main(){
     int numGen, current;
     int gameArr[9];
     int *nextGen = gameArr;
     int i = 0;
     printf("Please enter an integer for number of generations:\n");
     scanf("%d", &numGen);
     if(numGen >= 0){
          printf("\nPlease enter 9 integers (you can only enter either 0 or 1):\n");
          for(i = 0; i < 9; i++){
               scanf("%d", &current); 
               if(current == 0 || current == 1){
                    gameArr[i] = current;
               }
          }
          // The original matrix 
          printf("\nThe Matrix Generation 0:\n");
          printMatrix(nextGen);
          
          // The new matrix until the numGen reached
          for(i = 0; i < numGen; i++){
               nextGen = generateNewMatrix(nextGen);
          }
          printf("\nThe Matrix Generation %d:\n", numGen);
          printMatrix(nextGen);
     }
     else{
          // terminate if numGen is not positive
          printf("Invalid number\n");
          return 0;
     }
}

