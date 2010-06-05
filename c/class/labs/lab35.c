#include <stdio.h>
#include <stdlib.h>

/*
 * LAB 35 push(), pop() .
 */


struct employee
        {
                char name[15];
                char ssn[10];
                int age;
                float salary;
	        struct employee * next;
        };

/* global top of stack pointer */
struct employee * top;





/* function protos */
void getrec(struct employee *);
void putrec(struct employee *);
void push(struct employee *);
void pop(struct employee *);

void main(void)
{
  char c = 'n';
  struct employee * new;

do
    {
      
          switch(c)
            {
            case '1':
	      new = (struct employee *) calloc(1,sizeof(struct employee));
	      if(new == NULL)
		{
		  printf("\n**Memory Allocation Failed**\n");
		  exit(EXIT_FAILURE);
		}
	      
	      getrec(new);
	      if(new == NULL)
		exit(EXIT_FAILURE);
	      
	      if(top->name == NULL) /* bottom * next will be NULL */
		top = new;
		
	      else
		push(new);
              
	      c = 'n';
              break;
              


            case '2':
	      if(top == NULL)
		printf("\n** Stack is empty.  Please enter a record.**\n");
	      
	      else
		pop(top);
	      
	      c = 'n';
	      break;
	      
              
	    case '3':
	      while(top != NULL)
		pop(top);
	      
	      c = 'X';
	      break;

              
            default:
              printf("\n\n\t1 -- Push\n");
              printf("\t2 -- Pop\n");
	      printf("\t3 -- Quit\n");
              printf("\nEnter your selection: ");
              
              scanf("%c",&c);
	      while(getchar() != '\n');
              break; 
            } /* end of switch */
    }while(c != 'X'); 
}


void push(struct employee * new)
{
  new->next = top;
  top = new;
}



void pop(struct employee * temp)
{
  putrec(temp);
  
  top = temp->next;
  
  free(temp);
}



void getrec(struct employee * temp)
{
  char eol;
  int r = 0;
  
  printf("\nEnter the name, SS #, Age, Salary (separated by spaces): ");
  
  r = scanf("%s %s %d %f%c", &temp->name, &temp->ssn, &temp->age, &temp->salary,&eol);

  if(r!=5)
    {
      temp = NULL;
      printf("\n**Record entry not made. Please retry.**\n");
    }

  while(eol != '\n') eol = getchar();
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








