/* factorical function finder */
#include <stdio.h>

int main(){
  int x, y, z=1;

  printf("Enter a integer: ");
  scanf("%d",&x);

  y = x;

  while (y-1 > 0){
    z *= y * (y-1);
    y -= 2;
  }

  printf("The factorial of %d is: %d\n",x,z);
  printf("Such a task is better carried out using recursive functions instead of a while loop IMHO...");

  return 0;
}
