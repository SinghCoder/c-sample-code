#include "easyinp.h"

char *raw_input(char *message, size_t max_len){

    /* print any message provided (if any)  */
    if(message)
        printf("%s", message);

    /* recieve string of max specified size */
    char *input = malloc(sizeof(char)*max_len);
    input = fgets(input, max_len, stdin);

    /* clear any excess entered characters */
    char ch;
    int received_len = strlen(input);
    if( input[received_len-1] != '\n' ) // excess exists
        while((ch = getchar()) != '\n');
    
	input[received_len-1] = '\0';
    input = realloc(input, sizeof(char)*(received_len));

    return input;
    
}
