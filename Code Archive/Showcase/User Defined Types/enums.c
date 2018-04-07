#include <stdio.h>

typedef enum {WORKING, ERROR, PAUSED} STATUS;

enum DEMO {LEVEL0, LEVEL1, LEVEL2};

int main()
{
	enum DEMO main_demo = LEVEL2;
	STATUS main_status = WORKING;

	printf("Demo Level Code: %u\n", main_demo);
	printf("Status Code of this function: %u\n", main_status);

	return 0;
}
