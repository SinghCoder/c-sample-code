#include <stdio.h>
#include <string.h>

char get_type(char ch);

int main(){

	register int i;
	int vowels=0, consenents=0, other=0;
	char word[100];
	char type;

	printf("please enter a word: ");
	scanf("%[^\n]s", word);

	for(i=0;i<strlen(word);++i){

		type = get_type(*(word + i));
		switch(type){

			case 'V':
				vowels += 1;
				break;

			case 'C':
				consenents += 1;
				break;

			case 'O':
				other += 1;
				break;

		}

	}

	printf("The number of Vowels: %11d\nThe number of Consenents: %7d\nThe number of Other Characters: %d\n", vowels, consenents, other);

return 0;
}

char get_type(char ch){
	char vowels[] = {'A','E','I','O', 'U', 'a', 'e', 'i', 'o', 'u'};
	char consenents[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z', 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
	register int i;

	// test for vowels
	for(i=0;i<10;++i){
		if(ch == vowels[i]){
			return 'V';
		}
	}

	//test for consenents
	for(i=0;i<42;++i){
		if(ch == consenents[i])
			return 'C';
	}

	return 'O';
}
