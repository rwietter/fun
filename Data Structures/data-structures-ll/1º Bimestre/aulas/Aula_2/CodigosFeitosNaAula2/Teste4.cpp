#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct pos {
	int x;
	int y;
};

typedef struct pos Pos;

Pos* v;
int i;

main() {
	v = (Pos*) malloc(5*sizeof(Pos));
	int ax = 10;
	for(i=0;i<5;i++) {
		v[i].x = ax;
		v[i].y = ax++;
	}
	
	for(i=0;i<5;i++)
		printf("\n%d, %d",v[i].x, v[i].y);	
}
