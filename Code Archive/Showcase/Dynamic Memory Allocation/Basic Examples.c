#include <stdio.h>
#include <stdlib.h>

int main()
{
	size_t size = 10;
	int *m_arr = (int *)malloc(sizeof(int)*10);
	int *c_arr = (int *)calloc(10 ,sizeof(int)); // will initialize memory to zero, but malloc won't
	free(m_arr);
	free(c_arr);
	return 0;
}
