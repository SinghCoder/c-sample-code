#include <stdio.h>
#include <string.h>

struct student{
	char name[20];
	char id[14];
	int age;
	float cgpa;
} s1;

void fillStudent(struct student *s)
{
	printf("Name: ");
	scanf("%19[^\n]s", s->name);

	getchar();

	printf("ID: ");
	scanf("%13[^\n]s", s->id);

	getchar();

	printf("age: ");
	scanf("%d", &s->age);

	getchar();	

	printf("CGPA: ");
	scanf("%f", &s->cgpa);

	getchar();

}

void changeData(struct student s) {    // receives a structure argument
	strcpy(s.name,"Madhav");
	s.age = 20;
	s.cgpa = 7.33;
}


int main()
{
	struct student s2, s3, *s;
	printf("sizeof s1: %lu\n", sizeof(s1));
	printf("sizeof s2: %lu\n", sizeof(s2));
	printf("On my laptop, the bus size is 4, hence, char id[14] is getting buffered to 16 bytes.\n");

	putchar('\n');

	s = &s1;
	fillStudent(s);

	putchar('\n');

	s = &s2;
	fillStudent(s);

	s3 = s1;

	if( (!strcmp(s2.name, s3.name)) && (!strcmp(s2.id, s3.id)) && (s2.age == s3.age) && (s2.cgpa == s3.cgpa) )
		printf("The same.\n");
	else
		printf("Different.\n");

	changeData(s1);		// won't do jackshit

	putchar('\n');

	printf("part h:\n");
	printf("\tname: %s\n", s1.name);
	printf("\tid: %s\n", s1.id);
	printf("\tage: %d\n", s1.age);
	printf("\tcgpa: %0.2f\n", s1.cgpa);

	return 0;
}
