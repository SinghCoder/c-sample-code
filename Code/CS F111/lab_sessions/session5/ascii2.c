#include <stdio.h>

int main(){
	register int i;

	for(i=-128;i<=-1;++i){
		printf("%d corresponds to: **%c**\n", i, (char)i);
	}

return 0;
}
