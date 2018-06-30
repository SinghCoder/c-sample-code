#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	register int i;
	int n, seed, x;
	seed = time(NULL);
	srand(seed);
	for(i=0;i<5;++i){
		x = (rand())%40;
		if(x<20)
			x += 20;
		printf("%d\t", x);
	}
printf("\n");
return 0;
}
