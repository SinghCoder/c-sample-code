#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

char **createOrderedList(int n, ...){
	// ordering as per ASCII
	int i,j,c;
	char *current, *temp;
	char **ordered_list = (char **)malloc(sizeof(char *)*n);
	va_list provided_list;
	va_start(provided_list, n);
	ordered_list[0] = va_arg(provided_list, char *);
	for(i=1; i<n; ++i){ // i defines the max upper limit of comparisions.
		current = va_arg(provided_list, char *);
		for(j=0; j<i; ++j){ // j is used to find the right place for the string.
			if(strcmp(current, ordered_list[i]) > 0)
				continue;
			else{
				for(c=j-1; c=i; ++c){ // c is used for swaping.
					temp = ordered_list[c];
					ordered_list[c] = current;
					current = temp;
				}
			}
		}
	}
	return ordered_list;
	
}

int main(){
	int i;
	char **ordered_list = createOrderedList(5, "cat", "dog", "mouse", "bird", "frog");
	printf("Ordered List: \n");
	for(i=0; i<5; ++i){
		printf("%s ", ordered_list[i]);
	}
	printf("\n");
	for(i=0; i<5; ++i){
		free(ordered_list[i]);	
	}
	free(ordered_list);
	return 0;
}
