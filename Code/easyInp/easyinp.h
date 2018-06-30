/* Remember to compile with easyinp.c */

#ifndef EASYINP_H
#define EASYINP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *raw_input(char *message, size_t max_len); 
/* the last character will always be '\0' so keep that in mind, e.g. if you want a word of length 10, make max_len 11 to accomodate the terminating character. */

#endif // EASYINP_H 
