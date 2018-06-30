/* using the stdlib.h library, we can execute terminal (bash) commands with the system() function -- for Unix/POSIX systems only*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("echo \" Just a sample of the power this enables.\n \"");
	printf("The above statement was executed by the echo command.\n");


	// a sample of the power
	system("mkdir folder");
	system("touch folder/rep.c");

	system("echo \"#include <stdio.h>\nint main(){printf(\\\"replication!!!!!!!!!!!!!\\\");return 0;}\" > folder/rep.c ");
	system("gcc folder/rep.c -o folder/rep");
	system("folder/rep");

	return 0;
}
