#include <stdio.h>

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

count = 1;
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

printf("Number of terms = %d\n",count);
return 0;
}
