#include <stdio.h>

#define ORDEM 3

int mat[ORDEM][ORDEM] = {{2,5,6},
				         {1,6,7},
				         {-1,2,3}}, 
	matDet[ORDEM][ORDEM+2];

void criaMatDet(void) {
	int i, j;
	for(i=0;i<ORDEM;i++) // 0,1,2
		for(j=0;j<ORDEM;j++) // 0,1,2
				matDet[i][j] = mat[i][j];
	int k = 0, l = 3;
	for(i=0;i<ORDEM;i++) { 
		for(j=0;j<ORDEM-1;j++) { 
				matDet[k][l] = mat[i][j];			
				l++;
		}
		k++;
		l = 3;
	}
	puts("MATRIZ DETERMINANTE:");
	for(i=0;i<ORDEM;i++) {
		for(j=0;j<ORDEM+2;j++) 
				printf("%d, ", matDet[i][j]);
		puts("");
	}
		
	
}

void sarrus(void) {
	/*Produto([00]*[11]*[22])+
	Produto([01]*[12]*[23])+
	Produto([02]*[13]*[24])*/
	int i;
	float p1 = 1, p2 = 1, p3 = 1;
	for(i=0;i<ORDEM;i++) {
		p1 *= matDet[i][i];
		p2 *= matDet[i][i+1];
		p3 *= matDet[i][i+2];
	}
	float s1 = p1 + p2 + p3;
	printf("\n%f, ", s1);
	/*Produto([20]*[11]*[02])+
	Produto([21]*[12]*[03])+
	Produto([22]*[13]*[04])*/
	p1 = 1, p2 = 1, p3 = 1;
	int j = 2;
	for(i=0;i<ORDEM;i++) {
		p1 *= matDet[j][i];
		p2 *= matDet[j][i+1];
		p3 *= matDet[j][i+2];
		j--;
	}		
	float s2 = p1 + p2 + p3;
	printf("\n%f, ", s2);
	printf("\nDET = %f, ", s1 - s2);
}

main() {
	criaMatDet();
	sarrus();
} 
