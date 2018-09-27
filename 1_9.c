#include <stdio.h>


//Copy its input to its output, replacing each string of one or more blanks by a single blank (1.9)
int main(void){
  int c;
  int next;
  while((c = getchar())!= EOF){
    if(c == ''){
      next = getchar();
      if(next == ''){
        c = next;
      }
      else{
        putchar(c);
      }
    }
    else{
      putchar(c);
    }
  }
  return 0;
}


