#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <unistd.h>

int main()
{
	char plaintext[101];
	char salt[3];
	
	printf("plaintext: ");
	scanf("%[^'\n']s", plaintext);
	getchar();

	printf("salt(2 characters only): ");
	scanf("%2[^'\n']s", salt);
	getchar();
	
	char *encrypted = crypt(plaintext, salt);
	
	printf("encrypted text: %s\n", encrypted);
	return 0;
}

