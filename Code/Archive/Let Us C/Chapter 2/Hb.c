/* date: Dec 20 2017 */
/* given an input 5 digit number return an output 5 digit number */

#include <stdio.h>

int main(){
  int x, y, a, b, c, d, e, f, g, h;

  printf("please enter a 5 digit integer: ");
  scanf("%d", &x);
  printf("\n");

  printf("you have entered: %d\n", x);

  /* sample input: 23497 */

  a = x/10000;
  /* a = 2 */

  b = x/1000;
  /* b = 23 */
  c = b%(a*10);
  /* c = 3 */

  d = x/100;
  /* d = 234 */
  e = d%(b*10);
  /* e = 4 */

  f = x/10;
  /* f = 2349 */
  g = f%(d*10);
  /* g = 9 */

  h = x%(f*10);
  /* h = 5 */

  y = h*10000 + g*1000 + e*100 + c*10 + a;
  printf("%d\n", y);

  return 0;
}
