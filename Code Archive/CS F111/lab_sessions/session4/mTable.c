#include <stdio.h>

int main(){
	int x;
	register int i=0;
	printf("table for: ");
	scanf("%d", &x);

	for(i=0;i<10;++i)
		printf("%d x %d = %d\n", x, i+1, x*(i+1));
return 0;
}
