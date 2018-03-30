/* work needed!!! */

#include <stdio.h>
void binary(int num, char *base);
void printBin(char *base);
void oneComp(char *bin, char *onec);
char charify(int num);
int main(){
	int num;
	char bin[16] = {"0000000000000000"}, onec[16], twoc[16];
	printf("Please enter an integer: ");
	scanf("%d", &num);
	
	binary(num, bin);	/* bin means &bin[0] */ /* mixed call */	
	printBin(bin);
	
	oneComp();
	
	return 0;
}

void binary(int num, char *base){
	register int i;
	int x = num;
	for(i=0;i<16;++i){
		*(base + 15 - i) = charify(x%2);
		x = x/2; 
		if (x == 0)
			break;
	}
}

void printBin(char *base){
	register int i;
	for(i=0;i<16;++i){
		printf("%c", *(base + i));
	}
	printf("\n");
}

void oneComp(char *bin, char *onec){
	register int i;
	for(i=0;i<16;++i){
		if(bin[i] == "1")
			onec[i] = "0";
		else
			onec[i] = "1";
	}
}

char charify(int num){
	if (num == 1)
		return '1';
	else
		return '0';
}
