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
int comp(const void *p1, const void * p2);


void main(void)
{
  char c = 'n';
  char  b, sname[15];
  static int x;
  int a, y, r;
  a = r = 0;
  
  do
    {
      b = '\0';

	  switch(c)
	    {
	    case '1':
	      getrec(&worker[x++]);
	      c = 'n';
	      break;
	      


	    case '2':
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
	      

	      
	    case '3':
	      for(y=0; y < x; y++)
		putrec(&worker[y]);
	      
	      c = 'n';
	      break;
	      

	      
	    case '4':
	      qsort(worker, x, sizeof(struct employee), comp);
	      
	      c = 'n';
	      break;
	      

	    case '5':
	     r= init(&worker)
		c = 'n';
	      break
	      
	      
	    default:
	      printf("\n\n\t1 -- Add a record\n");
	      printf("\t2 -- Search for a record\n");
	      printf("\t3 -- Print all records\n");
	      printf("\t4 -- Sort the records\n");
	      printf("\t5 -- Initialize\n");
	      printf("\tq -- Quit\n");
	      printf("\nEnter your selection: ");
	      
	      scanf("%c",&c);
	      while(b!='\n')  b = getchar();
	      break; 
	    } /* end of switch */
    }while(c != 'q'); 
}

int init(struct employee * temp)
{

  strcpy(temp->name,"\0");
  strcpy(temp->ssn,"\0");
  temp->age={10};
  temp->salary={1.00};

  if(temp->age == 10)
    printf("\nAGE = 10\n");

return 1;




}






int comp(const void *p1, const void * p2)
{
  const struct employee *ps1 = p1 ;
  const struct employee *ps2 = p2 ;
  int r ;
  
  r = strcmp(ps1->name, ps2->name) ;
  if (r != 0)
    return r ;
  else
    return strcmp(ps1->ssn, ps2->ssn);
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









