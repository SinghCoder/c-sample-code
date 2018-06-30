#include <stdio.h>

int main(){
	register int i = 0;
	int x = 0;

	for(i=0;i<=255;++i){
		x += 1;
		printf("with %%hhu, though x is an int: %hhu\n", x);
	};

	return 0;
}
