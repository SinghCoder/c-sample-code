 	#include <stdio.h>

  int main()
  {

    /* PART 1 */
    printf("\nPART 1\n");
    int x = 10, *p = &x;
    int y = 12, *q = &y;

    printf("x: %d\ny: %d\n", x, y);
    printf("&x: %lu\n&y: %lu\n", (long unsigned int)&x, (long unsigned int)&y);

	putchar('\n');

    printf("*p: %d\n*q: %d\n", *p, *q);
    printf("p: %lu\nq: %lu\n", (long unsigned int)p, (long unsigned int)q);

        putchar('\n');

    printf("q - p: %lu\n", (long unsigned int)(q - p));
    printf("the size of a pointer is: %lu\n\n", sizeof(p));


    /* PART 2 */
    printf("\nPART 2\n");
    int arr[5] = {10, 15, 20, 10, 0};
    int *a = &arr[0];
    int *b = &arr[1];

    printf("arr[0]: %d\narr[1]: %d\n", arr[0], arr[1]);
    printf("&arr[0]: %lu\n&arr[1]: %lu\n", (long unsigned int)&arr[0], (long unsigned int)&arr[1]);

	putchar('\n');

    printf("*a: %d\n*b: %d\n", *a, *b);
    printf("a: %lu\nb: %lu\n", (long unsigned int)a, (long unsigned int)b);

	putchar('\n');

    printf("q - p: %lu\n", b- a);
    printf("the size of a pointer is: %lu\n\n", sizeof(a));

    return 0;
  }

