#include <stdio.h>

typedef void (*callback)(char*);

void evade(char* target){
	printf("%s evades!\n", target);
}

void damage(char* target){
	printf("%s receives damage!\n", target);
}

void ko(char *target){
	printf("%s is knocked out!\n", target);
}

void attack(char* attacker, char* target, callback callbacks[3]){
	printf("%s attacks %s!\n", attacker, target);
	FILE *random = fopen("/dev/random", "r");
	int r = ((int)fgetc(random))%3;
	(callbacks[r])(target);
	fclose(random);
}

int main(){
	callback callbacks[3] = {&evade, &damage, &ko}; 
	attack("charmander", "meowth", callbacks);
	return 0;
}
