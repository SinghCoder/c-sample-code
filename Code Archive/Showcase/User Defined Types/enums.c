#include <stdio.h>

typedef enum {WORKING, ERROR, PAUSED} STATUS;

enum DEMO {LEVEL0=404, LEVEL1, LEVEL2};

int main()
{
	enum DEMO main_demo = LEVEL0;
	enum DEMO second_demo = LEVEL1;
	STATUS main_status = WORKING;

	printf("Demo Level Code: %20u\n", main_demo);
	printf("Second Demo Level Code: %20u\n", second_demo);
	printf("Status Code of this function: %20u\n", main_status);

	return 0;
}
