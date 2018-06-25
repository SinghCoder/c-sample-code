#include <stdio.h>

int foo(int a, char *b){
	printf("recieved %d by value and %c by reference.\n", a, *b);
	return a + (int)*b;
}

void runFunction(int (*func)(int, char*), int a, char* b){
	// executing the function recieved by reference.
	// just for example we have this extra function in between.
	// func is called the "callback" function in this example.
	printf("result of executing the function with 10 and a: %d\n", (*func)(a, b));
	return;
}

int main(){
	// every function has an address which is referenced on the call stack.
	printf("address of function foo: %p\n", foo);
	
	// set up the proper file pointer:
	int (*ptr)(int, char *);
	
	// pointing it towards the desired function:
	ptr = &foo;

	// passing the function pointer by reference.... wow!!!
	int a = 10;
	char b = 'a';
	runFunction(ptr, a, &b);

	return 0;
}
