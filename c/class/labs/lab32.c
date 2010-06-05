#include <stdio.h>


struct employee
	{
		char name[15];	
		char ssn[10];
		int age;
		float salary;
	};


/* function protos */
void getrec(struct employee *);
void putrec(struct employee *);


void main(void)
{
  struct employee temp;
  
  getrec(&temp);
  
  putrec(&temp);
}



void putrec(struct employee * temp)
{
  printf("\n\n");
  
  printf("Name  : %s\n", temp->name);
  printf("SS #  : %s\n", temp->ssn);
  printf("Age   : %d\n", temp->age);
  printf("Salary: %.2f\n", temp->salary);
  printf("........................\n");

}


void getrec(struct employee * temp)
{
  int r;
  
  printf("\nEnter your name, SS #, Age, Salary (separated by spaces): ");
  
  r = scanf("%s %s %d %f", &temp->name, &temp->ssn, &temp->age, &temp->salary);
  
  if((r != 4) || (r == EOF))
    printf("\n**Record entry not made. Please retry.**\n");
  
}












