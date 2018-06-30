#include "easyinp.h"

// #define INSIGHT
// un-comment the above macro definition if you wish to see some extra stats.

int main(){
    char *message1 = raw_input("Enter something: ", 11);
    printf("You've entered: %s\n", message1);

    #ifdef INSIGHT
    int len1 = strlen(message1);
    printf("length: %d -- ending: %d\n", len1, message1[len1]);
    #endif

    char *message2 = raw_input("Enter something else: ", 11);
    printf("You've entered: %s\n", message2);

    #ifdef INSIGHT
    int len2 = strlen(message2);
    printf("length: %d -- ending: %d\n", len2, message2[len2]);
    #endif

    free(message1);
    free(message2);
}
