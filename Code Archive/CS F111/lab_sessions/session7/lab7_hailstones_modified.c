#include <stdio.h>
int printHailstones(int val);
int printLimitHailstones(int val);

int main()
{
int val, term, count;

printf("Enter a +ve integer to generate the hailstone sequence: ");
scanf("%d",&val);
while (val <= 0)
{
   printf("Hailstone sequences only for +ve numbers. Please enter a positive number\n");
   printf("Try again: ");
   scanf("%d", &val);
}

count = printLimitHailstones(val);

printf("Number of terms = %d\n",count);
return 0;
}


int printHailstones(int val){
int count = 1, term;
printf("%d\n", val);
for (term = val; term != 1; )
{
   if (term % 2 == 0)
      term = term / 2;
   else
      term = (3 * term) + 1;
   printf("%d\n", term);
   count++;
};

return count;
}

int printLimitHailstones(int val){
int count = 1, term;
int a,b;

printf("please enter the limits you'd like to impose (space seperated)");
scanf("%d%d", &a, &b);

printf("%d\n", val);
for (term = val; term != 1; )
{
   if (term % 2 == 0)
      term = term / 2;
   else
      term = (3 * term) + 1;
   printf("%d\n", term);
   count++;
   if (term<b && term >=a)
	break;
};

return count;
}
