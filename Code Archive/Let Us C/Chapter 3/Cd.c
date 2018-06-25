#include <stdio.h>

int main(){
  int year, rel_year, a, b, lyf, x;

  printf("Please enter the year you wish to test: ");
  scanf("%d", &year);

 /* include leap year consideration */

 if (year > 2001)
    rel_year = year-2001;
 else
    rel_year = 2001-year;

  a = rel_year/4;  /* number of years divisible by 4 */
  b = rel_year/100 - rel_year/400; /* number of years divisible by 100 and not by 400 */
  lyf = a - b; /* leap_year_factor */

  x = ((rel_year*365) + lyf)%7;

  switch (x) {
    case 0:
      printf("Monday");
      break;
    case 1:
      printf("Tuesday");
      break;
    case 2:
      printf("Wednesday");
      break;
    case 3:
      printf("Thursday");
      break;
    case 4:
      printf("Friday");
      break;
    case 5:
      printf("Saturday");
      break;
    case 6:
      printf("Sunday");
      break;
  }
 printf("\n");
  return 0;
}
