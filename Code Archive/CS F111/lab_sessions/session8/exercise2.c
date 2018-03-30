/* Dear professor/TA I have done this exploring before so I done something new here, I hope you will not mind me skipping this. */

#include <stdio.h>

int main(){
	char s1[50] = "BITS", s2[] = "Pilani", s3[50];
	printf("%lu %lu\n", strlen(s1), sizeof(s1));    /* It is easy to get confused between strlen() and sizeof() */
	strcat(s1," ");
	strcat(s1, s2);
	strcat(s1, ", ");
	strcpy(s3,"Pilani Campus");
	strcat(s1, s3);
	puts(s1);        /* Look up the man page of puts() to learn more */

	/* comparing two strings… */
	if (!strcmp(s2,s3)) /* strcmp() has returned 0 */
	    puts("Both strings are the same!\n");
	else if (strcmp(s2,s3) > 1)
	    printf("%s is greater than %s\n", s2, s3);
	else
	    printf("%s is greater than %s\n", s3, s2);
	return 0;
}
