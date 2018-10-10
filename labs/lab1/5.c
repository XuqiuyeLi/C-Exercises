/*   Write a C main program that plays the following simplification of
     Conway's game of life.

     The program reads 10 integers from the terminal.
     The first integer is called numGen short for number of
     generations.  Check that it is positive and abort the run if it is
     not.  The remaining 9 integers must each be 0 or 1 (check that
     they are 0 or 1 and abort if not).

     View these 9 binary values as a 3x3 matrix.  So if the numbers
     were 1 1 1 0 1 0 1 0 1 you view them as
     1 1 1
     0 1 0
     1 0 1

     This matrix is called generation 0.

     Each element of the matrix is called a cell.  A cell has
     neighbors on top, bottom, left, right, and diagonals.  The four
     corner cells (matrix elements 0,0 0,2 2,0 2,2) each have only
     three neighbor; whereas, the middle cell (element 1,1) has eight
     neighbors.

     Generation 1 is calculated from generation 0 as follows.  First,
     for each cell in generation 0, count how many of its neighbors
     are 1.  If that count gives 2 or 3, the cell is 1 in generation
     1, If the count is neither 2 nor 3, the cell is 0 in generation
     1.

     Repeat this process to produce all 9 values in generation 1.

     Then, using the generation 1 matrix, calculate the generation 2
     matrix using the same procedure.

     Stop when you reach generation numGen and print the resulting
     3 by 3 matrix on the screen.  */



#include <stdio.h>

int validInt(int x){
     int y;
     if(x == 0 || x == 1){
          return 1;
     }
     else{
          scanf("%d", &y);
          return validInt(y);
     }
     return 0;
}

int main(){
     int numGen, current;
     int gameArr[9];
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
          printf("\nThe Matrix Generation %d:", numGen);
          for(i = 0; i < 9; i++){
               if(i == 3 || i == 6){
                    printf("\n");
               }
               printf("%d ", gameArr[i]);
          }
          printf("\n\n");

          // The new matrix

     }
     else{
          // terminate if numGen is not positive
          printf("Invalid number\n");
          return 0;
     }
}

