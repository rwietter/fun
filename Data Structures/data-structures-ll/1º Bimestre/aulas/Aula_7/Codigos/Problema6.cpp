#include <stdio.h>

/*long fat(long x) {
	long fat = 1;
	int i;
	for(i=1;i<=x;i++) 
		fat = fat * i;
	return fat;	
}*/

long fat(long x) {
	if (x == 1)
		return 1;
	return x * fat(x-1) ;	
}

main() {
	//printf("%d",fat(5));
	//scanf("%d",10);
	long n = 35;
	long x, y;
	x = n / 2;
	do {
		if (fat(x) <= n) {
			printf("\n%d!",x);
			n = n - fat(x);	
			printf("\n n = %d",n);
		}
		if (n != 2)
			x--;   
	} while (x>0);
}







