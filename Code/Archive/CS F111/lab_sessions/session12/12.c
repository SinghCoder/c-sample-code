#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
char idno[16];
char name[50];
char gender;		
int age;
char res_status;
float cgpa;
char emailaddress[40];
} STUD;

void populateRecords(STUD [], int);
void generateEmailAddress(char [], char []); /* definition given below main()*/
void storeEmailAddresses(STUD [], int);
void printRecords(STUD [], int);
float calculateAvgCG(STUD [], int);
void printCount(STUD [], int, int);
void printCGPASort(STUD *arr, int n);

int main()
{
  int nos, i;
  // more declarations here...
  
  
  scanf("%d",&nos);    /* number of student records in the file */
  getchar();   /* to eat away the \n character at the end of line */
  STUD rec[nos];    /* a VLA of structures being declared */ 			// not a VLA imho, we can't change the length after creation.
  
  populateRecords(rec,nos);     /* get data into the array */
  storeEmailAddresses(rec,nos);    /* generate and store email addresses */
  
  printRecords(rec,nos);    /* print records in the required format */
  
  printf("The mean CGPA of students is: %.3f\n\n", calculateAvgCG(rec,nos));
  
  printCount(rec,1,0); /* count and print student numbers gender-wise */ 
  printCount(rec,0,1); /* print student numbers acc. to resi. status */
  
  // code for printing CGPAs sorted according to ID numbers goes here...
  
  printCGPASort(rec, nos);
  
  return 0;
}

void populateRecords(STUD arr[], int n)
{
  register int i;
  for(i=0;i<n;++i)
  {
	scanf("%[^',']s", arr[i].idno);
	getchar();
	
	scanf("%[^',']s", arr[i].name);
	getchar();
	
	scanf("%c", &arr[i].gender);
	getchar();
	
	scanf("%d", &arr[i].age);
	getchar();
	
	scanf("%c", &arr[i].res_status);
	getchar();
	
	scanf("%f", &arr[i].cgpa);
	getchar();
  }
  return;
}

void generateEmailAddress(char idno[], char email[])
{
  char year[5];
  int i, yr, start, len, end;
  for (i = 0; i < 4; ++i)
    year[i] = idno[i];
  year[i]='\0';	  /* year now contains the year of admission as a string */
  yr = atoi(year); /* contents of year being converted into an int */
  
  strcpy(email,"f");
  strcat(email,year);  /* email array now has fxxxx, where xxxx is the year of admission */
  
  if (yr < 2017)  /* prior to 2017 admissions */ 
    start = 9;  /* start extracting the last three digits in the ID number */
  else
    start = 8; /* start extracting the last four digits in the ID number */
  
  len = strlen(email);
  end = 11; /* extract till the last digit of the ID number */
  for (i = start; i <= end; ++i)
    email[len++] = idno[i];
  email[len] = '\0';
  strcat(email,"@pilani.bits-pilani.ac.in"); /* last part of email address */
  return;
}

void storeEmailAddresses(STUD arr[], int n)
{
  register int i;
  for(i=0;i<n;++i)
  {
  	generateEmailAddress(arr[i].idno, arr[i].emailaddress);
  }
  return;
}

void printRecords(STUD arr[], int n)
{
  register int i;
  for(i=0;i<n;++i)
  {
    printf("%s %s\n", arr[i].idno, arr[i].name);
    printf("Gender: %c\n", arr[i].gender);
    printf("Age: %d\n", arr[i].age);
    printf("Residence Status: ");
    switch (arr[i].res_status)
    {
    	case('H'):
    		printf("Hostel\n");
    		break;
    	case('D'):
    		printf("Day scholar\n");
 			break;
 		default:
 			printf("N.A.\n");
    }
    printf("CGPA: %0.2f\n", arr[i].cgpa);
    printf("Email: %s\n\n", arr[i].emailaddress);
  }
  return;
}

float calculateAvgCG(STUD arr[], int n)
{
  float avg;
  register int i;
  for(i=0;i<n;++i)
  {
  	avg += arr[i].cgpa;
  }
  avg /= n;
  return avg;  
}

void printCount(STUD arr[], int gndr, int resi)
{
  register int i;
  if(gndr)			/* Gender Mode */
  {
  	int male;
  	int female;
  	for(i=0; arr[i].age != 0; ++i)
  	{
  		switch (arr[i].gender)
		{
			case('M'):
				++male;
				break;
			case('F'):
				++female;
	 			break;
	 		default:
	 			break;
		}
  	}
  	printf("No. of male students: %d\nNo. of female students: %d\n\n", male, female);
  }
  
  else if(resi)		/* Residential Status Mode */
  {
	int htl;
  	int dsc;
  	for(i=0; (arr + i)->age != 0; ++i)	// just for
  	{
  		switch (arr[i].res_status)
		{
			case('H'):
				++htl;
				break;
			case('D'):
				++dsc;
	 			break;
	 		default:
	 			break;
		}
  	}
  	printf("No. of hostel resident students: %d\nNo. of day scholar students: %d\n\n", htl ,dsc);
  }
  
  return;		/* do nothing and return void if 0,0 was the selected option */
}

void printCGPASort(STUD *arr, int n)
{
	float far[n], temp;
	register int i,j;
	
	for(i=0;i<n;++i)		// get all CGPAs
	{
		far[i] = arr[i].cgpa; 
	}
	
	for(i=1;i<n;++i)	// apply an insertion sort
	{
		for(j=i;j>0;--j)
		{
			if(far[j] > far[j-1])
			{
				// swap
				temp = far[j];
				far[j] = far[j-1];
				far[j-1] = temp;
			}
			else
				break;
		}
	}
	
	for(i=0;i<n;++i)
	{
		printf("%0.2f\n", far[i]);
	}
}
