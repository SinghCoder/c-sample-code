/* print out all armstrong numbers b/w 1 and 500 */

#include <stdio.h>
#include <math.h>
/* if using GNU as your compiler
then remember to use the -lm flag
when compiling to link math */

int main(){
  int x=1,d1,d2,d3;

  while (x<=500){
      if (x<10){
          d1 = x;
          printf("%d\n",x);
      }
      else if (x<100){
          d1 = x/10;
          d2 = x%(d1*10);
          if ((pow(d1,2) + pow(d2,2)) == x)
              printf("%d\n",x);
      }
      else{
          d1 = x/100;
          d2 = (x%(d1*100))/10;
          d3 = x%(d1*100 + d2*10);
          if ((pow(d1,3) + pow(d2,3) + pow(d3,3)) == x)
              printf("%d\n",x);
      }
      x += 1;
  }

  printf("done!\n");
  return 0;
}
