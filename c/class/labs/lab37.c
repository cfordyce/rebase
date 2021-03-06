#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct employee
        {
                char name[15];
                char ssn[10];
                int age;
                float salary;
	        struct employee * next;
        };

struct employee * head;


/* function protos */
void getrec(struct employee *);
void putrec(struct employee *);
void search_rec(char *);
void insert_rec(void);
void dump_list(void);


void main(void)
{

struct employee * dump;

  char c = 'n';
  char sname[15];
  FILE * fp;
 
do
    {
    
          switch(c)
            {
            case '1':
	      insert_rec();
	      
	      c = 'n';
              break;
              


            case '2':
	      printf("\nEnter the name to search for: ");
              scanf("%s", sname);
	      while(getchar() != '\n');

              search_rec(sname);

	      c = 'n';
              break;




	    case '3':
	      if((fp = fopen("datafile.txt","w+")) != NULL)
		{
		  dump = head;
		  
		  while(dump != NULL)
		    {
		      fprintf(fp, "%s\t%s\t%d\t%.2f\n",dump->name, dump->ssn, dump->age,dump->salary);
		      
		      putrec(dump);
		      
		      dump = dump->next;
		    }
		  
		}
	      
	      else
		printf("\n**Failed: FILE OPEN**\n");
	      
	      c = 'X';
	      break;

	                    
              
            default:
              printf("\n\n\t1 -- Add a record\n");
              printf("\t2 -- Search for a record\n");
	      printf("\t3 -- Quit\n");
              printf("\nEnter your selection: ");
              scanf("%c",&c);
	      while(getchar() != '\n');
              
	      break; 
            }/* end of switch */
    }while(c != 'X'); 
}



void search_rec(char * sname)
{
  struct employee * search_head = head;
  while(search_head != NULL)
    {
      if(0 == strcmp(search_head->name, sname))
	{
	  putrec(search_head);
	  return;
	}
      
      search_head = search_head->next;
    }
  
  printf("\n**Record Not Found.**\n");
}





void insert_rec(void)
{
  
  struct employee * new, * curr;


  if(NULL == (new = (struct employee *) calloc(1,sizeof(struct employee))))
    {
      printf("\n**Memory Allocation Failed**\n");
      exit(EXIT_FAILURE);
    }

  else
    getrec(new);


  if(head == NULL)
    head = new;


  curr = head;


  if(-1==strcmp(new->name, curr->name))
    {
      new->next = head;
      head = new;
      return;
    }
  


  
  if(1==strcmp(new->name, curr->name)) /* new comes after */
    {

      struct employee * holdr;

      while(1==strcmp(new->name, curr->name))
	{
	  holdr = curr;
	  
	  if(curr->next == NULL)    /* curr is last */
	    {
	      new->next = curr->next;
	      holdr->next = new;
	      return;
	    }

	  if(curr != NULL)
	    curr = curr->next;

	} /* end while loop */
      
      holdr->next = new;
      new->next = curr;
    }
}



void getrec(struct employee * temp)
{
  char eol;
  int r = 0;
  
  printf("\nEnter the name, SS #, Age, Salary (separated by spaces): ");
  
  r = scanf("%s %s %d %f%c", temp->name, temp->ssn, &temp->age, &temp->salary,&eol);

  if(r!=5)
    {
      printf("\n**Record entry not made. Please retry.**\n");
      exit(EXIT_FAILURE);
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











