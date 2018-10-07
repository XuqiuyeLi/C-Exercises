#include <stdio.h>


// Write two versions of mkRectangle, one that accepts two points, and one that accepts 4 real numbers.

// I am really confused what this function returns????

// pointer version
void mkRectangle(struct point p1, struct point p2) {
	struct point p;
	p.x = p1.x;
	p.y = p2.y;

}

// four real numbers version







// How big is each version of sizeof(struct gameValType)? How big is sizeof employee?

	/*
	 * Answer:
	 * int requires 4 bytes, the struct gameValType has two int types, therefore the size is 8 bytes.
	 */
	struct gameValType {
    	int G;
    	int P;
  	} gameVal[ARRAYBOUND];





	/* Answer:
	 * Assume char requires 1 byte, int requires 4, and double requires 8, 
	 * so for each employeeType Struct it takes 16 bytes
	 * The employee array of 2 elments is 16 * 2 = 32 bytes
	 */
	#define NUMEMPLOYEES 2
  	struct employeeType {
    	int id;
    	char gender;
    	double salary;
  	} employee[NUMEMPLOYEES] = {
    	{ 32, 'M', 1234. },
    	{ 18, 'F', 1500. }
  	};