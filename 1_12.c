#include <stdio.h>


//Print its input one word per line (1.12)
int main() {
    int c;
    c = getchar();
    while ((c = getchar())!= EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');
        }
        else {
            putchar(c);
        }
        c = getchar();
    }
}