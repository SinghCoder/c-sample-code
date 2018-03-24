/* date: Dec 21st 2017 */
/* constants interchanging */

#include <stdio.h>

int main(){
  int x = 3;
  int y = 5;
  int a;

  a = x;
  x = y;
  y = a;

  printf("x was originally 3 but now it is %d\n", x);
  printf("y was originally 5 but now it is %d\n", y);

  return 0;
}
