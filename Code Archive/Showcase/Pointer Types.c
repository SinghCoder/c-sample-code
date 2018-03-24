/* Differentiating between 2D arrays and array of pointers */

#include <stdio.h>

int main()
{
	// Multidimensional
	int matrix1[3][3] = {
							{1, 2, 3},
							{4, 5, 6},
							{7, 8, 9}
				};

	char matrix2[3][10] = {
						{'H', 'y', 'p', 'r', 'o', '\0'},
						"Hypro999",		// just to show that this is also possible
						{'Y', 'U', '-', 'G', 'I', '-', 'O', 'H', '!', '\0'},							
				};

	// Pointers 						
	char *parray[3] = {
						"Hemanth",
						"Hypro",
						"Hypro999",
				};

	int (* pointertoarray1)[3] = matrix1;
	char (* pointertoarray2)[10] = matrix2;

	putchar('\n');

			printf("Multidimensional Array Stats:\n");
	
				printf("\n\tint matrix1[3][3]\n\n");
			printf("matrix1           : int (*)[3]   : %p\n", matrix1);	 // the [3] is for the array length to know how much to jump
			printf("*matrix1          : int *        : %p\n", *matrix1);
			printf("**matrix1         : int          : %d\n", **matrix1);

				printf("\n\tchar matrix2[3][10]\n\n");
			printf("matrix2           : char (*)[10] : %p\n", matrix2);	// constant string
			printf("matrix2 + 1       : char (*)[10] : %p\n", matrix2 + 1);	// array string
			printf("matrix2 + 2       : char (*)[10] : %p\n", matrix2 + 2);	// constant string
			printf("*matrix2          : char *       : %s\n", *matrix2);
			printf("*(matrix2 + 1)    : char *       : %s\n", *(matrix2 + 1));
			printf("*(matrix2 + 2)    : char *       : %s\n", *(matrix2 + 2));

	printf("\n\n");

			printf("Array of Pointer Stats:\n");

				printf("\n\tchar *parray[3]\n\n");
			printf("parry             : char **      : %p\n", parray);
			printf("*paray            : char *       : %s\n", *parray);
	
				printf("\n\tint (* pointertoarray)[3] = matrix1\n\n");
			printf("pointertoarray1   : int (*)[3]   : %p\n", pointertoarray1);
			printf("*pointertoarray1  : int *        : %p\n", *pointertoarray1);
			printf("**pointertoarray1 : int          : %d\n", **pointertoarray1);


				printf("\n\tchar (* pointertoarray)[10] = matrix2\n\n");
			printf("pointertoarray2   : char (*)[10] : %p\n", pointertoarray2);
			printf("*pointertoarray2  : char *       : %s\n", *pointertoarray2);

	putchar('\n');

	return 0;
}

