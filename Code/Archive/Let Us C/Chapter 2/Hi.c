/* date: Dec 21st 2017*/
/* possible denoominations: 1, 2, 5, 10, 50, 100*/

#include <stdio.h>

int main(){
  int n;
  int r;
  int a, b, c, d, e;

  printf("Please enter the sum: ");
  scanf("%d", &n);
  printf("\n");

  /* conditionals and loop control statements avoided for now. */

  a = n/100;
  r = n % 100;

  b = r/50;
  r = r % 50;

  c = r/10;
  r = r % 10;

  d = r/5;
  r = r % 5;

  e = r/2;
  r = r % 2;

  printf("100s: %d\n50s:  %d\n10s:  %d\n5s:   %d\n2s:   %d\n1s:   %d\n",a,b,c,d,e,r);

  return 0;
}
