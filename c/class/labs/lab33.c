#include <stdio.h>
#include <stdlib.h>

struct employee
        {
                char name[15];
                char ssn[10];
                int age;
                float salary;
        } worker[100];

/* function protos */
void putrec(struct employee * temp);
void getrec(struct employee * temp);
int searchrec(struct employee * worker, char *name, int x);


void main(void)
{
  char c = 'n';
  char  b, sname[15];
  int a = 0;
  static int x;

  
  do
    {
      b = '\0';

	  switch(c)
	    {
	    case 'a':
	      getrec(&worker[x++]);
	      c = 'n';
	      break;
	      


	    case 's':
	      printf("\nEnter the name to search for: ");
	      scanf("%s", sname);
	      while(b!='\n')  b = getchar();
	      b = '\0';

	      a = searchrec(worker, sname, x);

	      if (a == -1)
		printf("\nRecord not found.\n");
	      
	      if(a != -1)
		putrec(&worker[a]);
	      
	      c = 'n';
	      break;


	      
		      
	    default:
	      printf("\n\n\ta -- Add a record\n");
	      printf("\ts -- Search for a record\n");
	      printf("\tq -- Quit\n");
	      printf("\nEnter your selection: ");

	      scanf("%c",&c);
	      while(b!='\n')  b = getchar();
	      break; 
	    } /* end of switch */
	  
    }while(c != 'q'); 
}


int comp(const void * p1, const void * p2)     /*page 599, Prata book */
{
  const struct employee *ps1 = p1 ;
  const struct employee *ps2 = p2 ;
  int res ;
  
  res =strcmp (ps1-> name , ps2 -> name) ;
  if (res != 0)
    return res ;
  
  else
    return strcmp(ps1->ssn , ps2->ssn);
  
}











int searchrec(struct employee * worker, char *name, int x)
{
  /*
   * Search for a record that matches the name string passed 
   */
int r = 0;

for(; r <= x; r++)
  if (0 == (strcmp(worker[r].name, name)))
    return r;

return -1;
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
  char eol;
  int r = 0;
  
  printf("\nEnter the name, SS #, Age, Salary (separated by spaces): ");
  
  r = scanf("%s %s %d %f%c", &temp->name, &temp->ssn, &temp->age, &temp->salary,&eol);

  if(r!=5)
    printf("\n**Record entry not made. Please retry.**\n");
    
    while(eol != '\n') eol = getchar();
    
}









