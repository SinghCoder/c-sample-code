#include <stdio.h>

int main(){

  int year;

  printf("Please enter the year you wish to test: ");
  scanf("%d", &year);
  printf("\n");

  if (year%4==0)
  {
    if (year%100==0)
    {
      if (year%400==0)
      {
        printf("It's a leap year.\n");
      }
      else
      {
        printf("Not a leap year.\n");
      }
    }
    else
    {
      printf("It's a leap year.\n");
    }
 }
 else
 {
   printf("Not a leap year.\n");
 }

}
