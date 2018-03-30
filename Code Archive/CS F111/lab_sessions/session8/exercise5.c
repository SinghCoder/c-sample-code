#include <stdio.h>
#include <string.h>

void strrev(char *a) /* function to reverse the given string */
{
  char *b, temp;
  b = a + strlen(a) - 1;    /* b is made to the last character preceding 
the terminating \0 */
  for (  ; a < b ; a++, b--)        
         {        /* swapping the contents pointed to by a and b */
          temp = *a;
          *a = *b;
          *b = temp;
        }
  return;
}

int isPalind_1(char arr[]){
	register int i;
	int length = strlen(arr);
	for(i=0;i<(length/2);++i){
		if(arr[i] == arr[length-i-1])
		 	continue;
		else
			printf("%d vs %d", arr[i], arr[length-i]);
			return 0; // if not palindrome
	}
	return 1;	// if not palindrome
}

int isPalind_2(char *arr){
	register int i;
	int length = strlen(arr);
	for(i=0;i<(length/2);++i){
		if(*(arr + i) == *(arr + length - i - 1))
		 	continue;
		else
			return 0;	// if palindrome
	}
	return 1;	// if not palindrome
}

int isPalind_3(char *arr){
	char arr_copy[100];
	int result;
	strcpy(arr_copy, arr);
	result = strcmp(arr, arr_copy);
	if(result == 0)
		return 1;
	else
		return 0;
}

int main(){
	char arr1[100];

	printf("Enter a string: ");
	scanf("%[^\n]", arr1);

	getchar();

	printf("Test 1: \n");
	if(isPalind_1(arr1))
		printf("Array is a palindrome.\n");
	else
		printf("Array is not a palindrome.\n");

	printf("Test 2: \n");
	if(isPalind_2(arr1))
		printf("Array is a palindrome.\n");
	else
		printf("Array is not a palindrome.\n");

	printf("Test 3: \n");
	if(isPalind_3(arr1))
		printf("Array is a palindrome.\n");
	else
		printf("Array is not a palindrome.\n");

	return 0;
}
