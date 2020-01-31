#include <stdio.h>

int main(){
	register int i;

	for(i=0;i<=255;++i){
		printf("%d corresponds to: **%c**\n", i, (char)i);
	}

return 0;
}
