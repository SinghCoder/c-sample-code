#include <stdio.h>

enum mode {ground, water, air};

struct vehicle {
	unsigned mode :2; // from enum mode
	unsigned civilian :1; // 1 or 0 as in True or False
	unsigned wheels :5; // 16 at max
}; // should be accomodated in the space of a single integer.

void displayVehicle(const char *name, const struct vehicle vec){
	printf("Effectively stored entry \"%s\":\n ", name);
	printf("  mode: %d\n", vec.mode);
	printf("  civilian: %d\n", vec.civilian);
	printf("  wheels: %d\n", vec.wheels);
	return;
}

int main(){
	struct vehicle motorbike;
	motorbike.mode = ground;
	motorbike.civilian = 1;
	motorbike.wheels = 2;
	displayVehicle("motorbike", motorbike);
	return 0;
}
