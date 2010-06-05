
/******************************************************************************
 *
 * File: ex2.c
 *
 * System: C Programming Advanced, Exercise 2
 * 
 * Description: This program tests parsing a simple string using
 *    3 methods.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 06-Oct-2000  Charles Fordyce     blah    
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

/***************************************************************************
 * structure declarations
 ***************************************************************************/
#define NAME_LEN (20)

#ifndef TRUE
#define TRUE  (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif

/***************************************************************************
 * structure declarations
 ***************************************************************************/
struct parse_s
{
    double value;
    char name[NAME_LEN + 1];
};

/***************************************************************************
 * prototypes
 ***************************************************************************/
static void print_parse( char * parse_str, struct parse_s * parse_struct );
static int parse_sscanf( char * in_str, struct parse_s * parse_struct );
static int parse_strtok( char * in_str, struct parse_s * parse_struct );
static int parse_no_stdlib( char * in_str, struct parse_s * parse_struct );

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
    int inx = 0;
    struct parse_s parse;
    char * test[] = { "some-number-name  123.456", 
                      "pi*100            314.159", 
                      "pi*100000         314159", 
                      "pi/10             0.314159", 
                      "123.45            123.45", 
                      "pi*100            314.159", 
                      "a-neg-number      -123.456", 
                      "zero-number       0.0", 
                      "another-zero      0", 
                      /** these may or may not fail - depends on definition **/
                      "some-really-long-name-string     123.456",  
                      "pi                3.1.4159",
                      "some-number       499.999 extra 299.999",
                      /** these should fail */
                      "",
                      "no-num",
                      "invalid-num       xxx",
                      "123.45            name-in-wrong-position",
                      "                  123.45" };
#ifdef MY_DEBUG
    freopen( "logfile.txt", "w", stdout );
    freopen( "errfile.txt", "w", stderr );
#endif

    puts( "********************" );
    puts( "Testing parse_strtok" );
    puts( "********************" );
    for ( inx = 0; inx < sizeof(test)/sizeof(char *); inx ++ )
    {
        memset( &parse, 0, sizeof( parse) );
        if ( parse_strtok( test[inx], &parse ) )
            print_parse( test[inx], &parse );
        else
            fprintf( stderr, "Failed to parse >>%s<<\n", test[inx] );
    }

    puts( "********************" );
    puts( "Testing parse_sscanf" );
    puts( "********************" );
    for ( inx = 0; inx < sizeof(test)/sizeof(char *); inx ++ )
    {
        memset( &parse, 0, sizeof( parse) );
        if ( parse_sscanf( test[inx], &parse ) )
            print_parse( test[inx], &parse );
        else
            fprintf( stderr,  "Failed to parse >>%s<<\n", test[inx] );
    }

    puts( "********************" );
    puts( "Testing parse_no_stdlib" );
    puts( "********************" );
    for ( inx = 0; inx < sizeof(test)/sizeof(char *); inx ++ )
    {
        memset( &parse, 0, sizeof( parse) );
        if ( parse_no_stdlib( test[inx], &parse ) )
            print_parse( test[inx], &parse );
        else
            fprintf( stderr,  "Failed to parse >>%s<<\n", test[inx] );
    }
    return EXIT_SUCCESS;
}

/***************************************************************************
 * Function: print_parse
 * Description: print string and parsed string from struct
 * Input:
 *   parse_str - string that was parsed
 *   parse_struct - structure string was parsed in to
 * Output:
 *   none
 * Return:
 *   none
 * Special Logic:
 *   none
 ***************************************************************************/
static void print_parse( char * parse_str, struct parse_s * parse_struct )
{
    printf( "Success parsed >>%s<< to >>%s<< and %f\n", 
         parse_str, parse_struct->name, parse_struct->value );
}

/***************************************************************************
 * Function: parse_sscanf
 * Description: parse string using sscanf
 * Input:
 *   in_str - string to parse
 * Output:
 *   parse_struct - pointer to structure to add data to
 * Return:
 *   TRUE - sucessfully parsed and updated parse_struct
 *   FALSE - some error encountered
 * Special Logic:
 *   When FALSE returned, parse_struct is NOT modified 
 *   Input and Output pointers must be to non-NULL.
 ***************************************************************************/
static int parse_sscanf( char * in_str, struct parse_s * parse_struct )
{
  char wk_str[100], temp_name[20];
  float temp_val = 0;
  
  strcpy(wk_str, in_str);
  
  if(2 != (sscanf(wk_str,"%s %f",temp_name,&temp_val)))
    return FALSE;
  
  if(strlen(temp_name) > 20)
    return FALSE;

  /**************************************
   All tests passed, send back Success
  **************************************/
  strcat(parse_struct->name,temp_name);
  parse_struct->value = temp_val;
  return TRUE;

}


/***************************************************************************
 * Function: parse_strtok
 * Description: parse string strtok and other stdlib functions
 * Input:
 *   in_str - string to parse
 * Output:
 *   parse_struct - pointer to structure to add data to
 * Return:
 *   TRUE - sucessfully parsed and updated parse_struct
 *   FALSE - some error encountered
 * Special Logic:
 *   When FALSE returned, parse_struct is NOT modified 
 *   Input and Output pointers must be to non-NULL.
 ***************************************************************************/
static int parse_strtok( char * in_str, struct parse_s * parse_struct )
{
  char wk_str[100], *token[10];
  char *in_p_pt;
  int tkn = 0;
  double d;

  strcpy(wk_str, in_str);

  /***********************
   Initialize token array 
  ***********************/
  for(;tkn == 1; tkn++)
    *(token + tkn) = NULL;
  
  tkn = 0;
  
  token[tkn++] = strtok(wk_str, " ");
  
  while(token[tkn++] = strtok(NULL," "));
  
  if(!token[0] || !token[1] || token[2])
    return FALSE;
  
  if(strlen(token[0]) > 20)
    return FALSE;
  
  d = strtod(token[1], &in_p_pt);
  if(d == 0.0 && in_p_pt == token[1])
    return FALSE;
  
  /**************************************
   All tests passed, send back Success
  **************************************/
  strcat(parse_struct->name,token[0]);
  parse_struct->value = d;
  return TRUE;
}

/***************************************************************************
 * Function: parse_no_stdlib
 * Description: parse string without calls to *stdlib* - except strtod,strncpy,strcpy
 * Input:
 *   in_str - string to parse
 * Output:
 *   parse_struct - pointer to structure to add data to
 * Return:
 *   TRUE - sucessfully parsed and updated parse_struct
 *   FALSE - some error encountered
 * Special Logic:
 *   When FALSE returned, parse_struct is NOT modified 
 *   Input and Output pointers must be to non-NULL.
 ***************************************************************************/
static int parse_no_stdlib( char * in_str, struct parse_s * parse_struct )
{
  char wk_str[100], temp_name[20], temp_val[30];
  char *in_p_pt;
  double d = 0.0;
  int wix, nix, vix;
  wix = nix = vix = 0;
  
  /*******************
   Initialize arrays
  *******************/
 
  for(; wix < 100; wix++)
    wk_str[wix] = '\0';

  for(;nix < 20; nix++)
    temp_name[nix] = '\0';

  for(;vix < 30; vix++)
    temp_val[vix] = '\0';


  strcpy(wk_str, in_str);
    
  if(wk_str[0] == '\0')
    return FALSE;
  
  
  /********************
   populate name array
  ********************/

  nix = 0;

  while(wk_str[nix] != ' ')
    {
      temp_name[nix] = wk_str[nix];

      if(temp_name[nix] == '\0' || nix == 20)
	return FALSE;

      nix++;
    }
  
  if(temp_name[0] == '\0')
    return FALSE;
  
  while(wk_str[nix] == ' ') nix++;
  
  
  /**********************
   populate value array
  **********************/
							     
  vix = 0;
  
  while(wk_str[nix] != '\0')
    {
      temp_val[vix++] = wk_str[nix++]; 
    }
  
  if(temp_val[0] == '\0')
    return FALSE;

  d = strtod(temp_val, &in_p_pt);
  if(d == 0.0 && in_p_pt == temp_val)
    return FALSE;
  

  /**************************************
   All tests passed, send back Success
  **************************************/
  strcpy(parse_struct->name,temp_name);
  parse_struct->value = d;
  return TRUE;
}
