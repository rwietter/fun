#include <stdio.h>

int m[5][5] = {{1,7,7,7,7},
			   {6,2,7,7,7},
			   {6,6,3,7,7},
			   {6,6,6,4,7},
			   {6,6,6,6,5}};

main() {
	int troca, i, j;
	for(i=0;i<5;i++) // linhas
		for(j=0;j<5;j++) // colunas
			if (i!=j) {
				troca = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = troca;
			}
	for(i=0;i<5;i++) {// linhas
		for(j=0;j<5;j++)// colunas
			printf("%d, ",m[i][j]);		
		puts("");
    }
	    
}

