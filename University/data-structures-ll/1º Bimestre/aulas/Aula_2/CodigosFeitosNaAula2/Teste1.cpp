#include <stdio.h>

struct ponto {
	float x; // 5
	float y; // 6
};

typedef struct ponto Ponto;

Ponto p;

main() {
	p.x = 5;
	p.y = 6;
	printf("%f %f",p.x,p.y);
}

