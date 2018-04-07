/* 
	Structures are more akin to variables than arrays 
	When using scanf for int, float or char attributes, stuff that don't have a pointer associated with them (unlike with strings), use & op.
*/

#include <stdio.h>
#include <string.h>

struct TEACHER {
	char name[20];
	int age;
	char subject[32];	// might as well give this extra space instead of letting it get wasted in "padding".
};

typedef struct {
	char name[20];
	int age;
	int class;
	float cgpa;
} STUDENT;

int main()
{
	struct TEACHER t;
	strcpy(t.name, "The Ancient One");
	t.age = 500;
	strcpy(t.subject, "The Mystic Arts");

	STUDENT s1;
	strcpy(s1.name, "Mordu");
	s1.age = 45;
	s1.class = 100;
	s1.cgpa = 9.5;

	STUDENT s2;
	STUDENT *s3 = &s2;
	strcpy(s3->name, "Dr. Strange");
	s2.age = 45;
	s2.class = 100;
	s3->cgpa = 9.8;

	printf("TEACHER: %s\n\tage: %d\n\tsubject: %s\n", t.name, t.age, t.subject);
	printf("STUDENT: %s\n\tage: %d\n\tclass: %d\n\tcgpa: %0.2f\n", s1.name, s1.age, s1.class, s1.cgpa);
	printf("STUDENT: %s\n\tage: %d\n\tclass: %d\n\tcgpa: %0.2f\n", s3->name, s3->age, s3->class, s3->cgpa);

	return 0;	
}
