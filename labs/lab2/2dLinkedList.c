#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 255

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
struct node2d *mkExConfig();
// configuration for part 4
struct node2d *part4Config();


// external funs
void insertCommand(struct node2d *p2d);
void printConfig(struct node2d *p2d);
void print2dNode(struct node2d *p2d);
int print1dNode(struct node1d *p1d);
int insert(struct node2d *p2d, char* name2d, char* name1d);
int insertAlphabetically(struct node2d *p2d, char* name2d, char* name1d);


// main 
int main (void) {
    struct node2d *p2d;
    p2d = mkExConfig();
    //p2d = part4Config();
    printConfig(p2d);
    insertCommand(p2d);
    return 0;
}



void insertCommand(struct node2d *p2d){
    int c;
    // read commands for inserting a new 1dNode to an existing 2dNode
    printf("\nDo you want to insert a node?\n");
    while ((c = getchar()) != EOF) {
        int index1d = 0, index2d = 0;
        char *Name2d = (char *)malloc(sizeof(char)*MAXLENGTH);
        char *Name1d = (char *)malloc(sizeof(char)*MAXLENGTH);
        // check first 4 characters are "Ins "
        if(c != 'I' || (c=getchar()) != 'n' || (c=getchar()) != 's' || (c=getchar()) != ' '){
            printf("The command should start with 'Ins '\n");
            exit(2);
        }
        // get the name of the 2dNode to insert from
        while((c = getchar())){
            if (!isalnum(c)){
                break;
            }
            Name2d[index2d++] = c;   
        }
        if(c != ' '){
            printf("Only alphanumeric character allowed!\n");
            exit(2);
        }
    
        // get the name of the 1dNode for insertion
        while((c = getchar())){
            if (!isalnum(c)){
                break;
            }
            Name1d[index1d++] = c;   
        }
        if(c != '\n'){
            printf("Invalid format!\n");
            exit(2);
        }
        /*------------ Uncomment to insert alphabetically ------------*/
        insert(p2d, Name2d, Name1d);
        //insertAlphabetically(p2d, Name2d, Name1d);
    }
    print2dNode(p2d);
    printf("\nInsertion Complete.\n");
    // when EOF occurs free the malloced memory
    free(p2d);
    // clear the array
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

struct node2d *part4Config() {
    struct node2d *p2d;
    // create rows from bottom to top
    
    // create bottom row 
    p2d = mk2dNode(NULL, "R2D2", NULL);

    // create middle row
    p2d = mk2dNode(NULL, "alice", p2d);

    // create top row 
    p2d = mk2dNode(NULL, "joe", p2d);

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
    int num1d = 0; 

    while(current2d->down != NULL){
        string = (current2d == p2d) ? "first" : "next";
        printf("\nThe %s 2d node has name: %s\n", string, current2d->name);
        if(current2d->first != NULL){
            num1d += print1dNode(current2d->first);
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
    printf("\nThe number of 2d nodes: %d\nThe number of 1d nodes: %d\n", num2d, num1d);
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

int insert(struct node2d *p2d, char* name2d, char* name1d){
    struct node2d *current2d = p2d;
    struct node1d *current1d;
    struct node1d *insertNode;
    while(current2d->down != NULL){
        if((strcmp(current2d->name, name2d)) != 0){
            current2d = current2d->down;
        }
        else{
            break;
        }
    }
    // check if it's the last one or the matching 2d node
    if((strcmp(current2d->name, name2d)) == 0){
        insertNode = mk1dNode(name1d, NULL);
        if(current2d->first != NULL){
            current1d = current2d->first;
            while(current1d->next != NULL){
                current1d = current1d->next;
            }
            current1d->next = insertNode;
        }
        else{
            current2d->first = insertNode;
        }
        print2dNode(p2d);
        printf("\n\n\n\n");
        return 0;
    }
    printf("No such 2dNode is found\n");
    exit(2);

}


/*----------------- Part 4 ---------------------*/

/*
 * function for insertion of 1d nodes onto a given sub-list in alphabetical order
 */

int insertAlphabetically(struct node2d *p2d, char* name2d, char* name1d){
    printf("name2d: %s, name1d: %s \n", name2d, name1d);
    struct node2d *current2d = p2d;
    struct node1d *current1d;
    struct node1d *before;
    struct node1d *insertNode;
    while(current2d->down != NULL){
        printf("current2d node: %s, the insert 2d node: %s\n",current2d->name, name2d);
        if((strcmp(current2d->name, name2d)) != 0){
            current2d = current2d->down;
        }
        else{
            printf("matching node found! %s\n", name2d);
            break;
        }
    }
    // check if it's the last one or the matching 2d node
    if((strcmp(current2d->name, name2d)) == 0){
        insertNode = mk1dNode(name1d, NULL);
        printf("insertAlphabetically function new 1dNode:\n");
        if(current2d->first == NULL){
            current2d->first = insertNode;
        }
        else{
            current1d = current2d->first;
            before = NULL;
            // insert in the front
            if((strcmp(current1d->name, name1d)) >= 0){
                printf("%s \t, %s\n", current1d->name, name1d);
                insertNode->next = current1d;
                current2d->first = insertNode;
                printf("insert in the front\n");
            }
            else{
                // get to the second 1dNode
                before = current1d;
                current1d = current1d->next;
                // insert in the middle
                while(current1d->next != NULL){
                    printf("%s \t, %s\n", current1d->name, name1d);
                    // the node should be inserted before current node
                    if((strcmp(current1d->name, name1d)) >= 0){
                        insertNode->next = current1d;
                        before->next = insertNode;
                        printf("insert in the middle\n");
                        return 0;
                    }
                    before = current1d;
                    current1d = current1d->next;
                }
                // insert in the end
                current1d->next = insertNode;
                printf("insert in the end\n");
            }
        }
        print2dNode(p2d);
        return 0;
    }
    printf("No such 2dNode is found\n");
    exit(2);

}
