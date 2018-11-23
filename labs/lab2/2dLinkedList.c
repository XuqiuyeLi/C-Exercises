#include <stdlib.h>
#include <stdio.h>

// structs
struct node2d {
    struct node1d *first;
    char *name;
    struct node2d *down;
};
struct node1d {
    struct node1d *next;
    char *name;
};

// funs in this file
struct node1d *mk1dNode(char *name, struct node1d *next);
struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down);
struct node2d *mkExConfig ();
// external funs
void printConfig(struct node2d *p2d);
void print2dNode(struct node2d *p2d);
int print1dNode(struct node1d *p1d);

// main
int main (int argc, char *argv[]) {
    struct node2d *p2d;
    p2d = mkExConfig();
    printConfig(p2d);
    return 0;
}

struct node2d *mkExConfig() {
    struct node1d *p1d;
    struct node2d *p2d;
    
    // create rows from bottom to top
    
    // create bottom row from right to left
    p1d = mk1dNode("c3pO", NULL);
    p1d = mk1dNode("cso", p1d);
    p2d = mk2dNode(p1d, "R2D2", NULL);

    // create middle row
    p2d = mk2dNode(NULL, "alice", p2d);

    // create top row from right to left
    p1d = mk1dNode("e342", NULL);
    p1d = mk1dNode("sally", p1d);
    p1d = mk1dNode("xy2", p1d);
    p2d = mk2dNode(p1d, "joe", p2d);

    return p2d;
}

struct node1d *mk1dNode(char *name, struct node1d *next) {
    struct node1d *p1d;
    p1d = (struct node1d *)malloc(sizeof(struct node1d));
    (*p1d).next = next;   // (*p1d). is long form
    p1d->next = next;     // common abbreviation
    p1d->name = name;
    return p1d;
}

struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down) {
    struct node2d *p2d;
    p2d = (struct node2d *)malloc(sizeof(struct node2d));
    p2d->first = first;
    p2d->name  = name;
    p2d->down  = down;
    return p2d;
}


/*----------------- Part 1 ---------------------*/
void printConfig(struct node2d *p2d){
    print2dNode(p2d);
    printf("\nAll finished.\n");
}

/*----------------- Part 2 ---------------------*/
void print2dNode(struct node2d *p2d){
    struct node2d *current2d = p2d;
    char* string;
    int num2d = 0;
    int num1d; 

    while(current2d->down != NULL){
        string = (current2d == p2d) ? "first" : "next";
        printf("\nThe %s 2d node has name: %s\n", string, current2d->name);
        if(current2d->first != NULL){
            num1d = print1dNode(current2d->first);
        }
        num2d++;
        current2d = current2d->down;
    }
    //print the last 2d node
    string = (current2d == p2d) ? "first" : "next";
    printf("\nThe %s 2d node has name: %s\n", string, current2d->name);
    if(current2d->first != NULL){
        num1d += print1dNode(current2d->first);
    }
    num2d++;
    printf("\nThe number of 2d nodes: %d\n The number of 1d nodes: %d\n", num2d, num1d);
}

int print1dNode(struct node1d *p1d){
    struct node1d *current1d;
    char *string;
    int counter = 0;
    current1d = p1d;
    while(current1d->next != NULL){
        string = (current1d == p1d) ? "first" : "next";
        printf("\tThe %s 1d node has name: %s\t", string, current1d->name);
        counter++;
        current1d = current1d->next;
    }
    // print the last 1d node
    string = (current1d == p1d) ? "first" : "next";
    printf("\tThe %s 1d node has name: %s\n", string, current1d->name);
    counter++;
    return counter;
}

/*----------------- Part 3 ---------------------*/

/*
 * function for insertion of 1d nodes onto a given sub-list
 */

int insert(struct node2d *p2d, char* name){
    char* command;
    printf("Do you want to insert a node?\n");
    scanf("%s", command);
    if(command[0] != 'I' || command[1] != 'n' || command[2] != 's' || command[3] != ''){
        // print an error
        printf("The command format should be:\n Ins nameOf2dNode nameOf1dNodeToInsert\n");
        return 0;
    }
    printf("correct command");

}
