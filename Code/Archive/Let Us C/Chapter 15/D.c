#include <stdio.h>
#include <string.h>

void collectInput1(char *source);
void collectInput2(int *pos, int *len);
void output(char *user_string, int pos, int len);
void strprint(char *string, int start, int stop);

int main(){
	/* Input String */
	char user_string[50];
	collectInput1(user_string);

	/* Input Params */
	int pos, len;
	collectInput2(&pos, &len);

	/* Finishing Touch */
	output(user_string, pos, len)
}

void collectInput1(char *source){
	printf("Enter a small string here: ");
	scanf("%[^\n]s", source);
}


void collectInput2(int *pos, int *len){
	printf("Enter a crop start: ");
	scanf("%d", pos);

	if (pos != 0){
		printf("Enter a crop length: ");
		scanf("%d", len);
	}
}

void output(char *user_string, int pos, int len){
	/* situation1: the len and pos are normal*/
	/* situation2: the len overflows or is zero*/
	int situation, start, stop;
	if(pos+len <= (strlen(user_string)+1))
		situation = 1;
	else
		situation = 2;

	switch(situation){
		case 1:
			start=pos-1; stop=pos+len-2;
			strprint(user_string, start, stop);
			break;
		case 2:
			if(pos < strlen(user_string))
				printf("Out of Bounds");
			else
				start=pos-1; stop=strlen(user_string)-1;
				strprint(user_string, start, stop);
			break;
		default:
			printf("Issue in the code");
	}
}


/* the accepted start position will be use a start index of 0 */
void strprint(char *string, int start, int stop){
	int i;
	for(i=start; i<=stop; ++i){
		printf("%c", string[i]);
	}
	printf("\n");
}
