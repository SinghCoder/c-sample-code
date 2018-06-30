/* date: Dec 20th 2017 */
/* author: Hemanth V. Alluri*/
/* after less than 10 minutes of thinking about it, I got the answer by myself */
/* situation: given a five digit number, calculate the sum of its digits */

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

  y = a + c + e + g + h;

  printf("the sum of the digits is: ");
  printf("%d\n", y);
  return 0;
}
