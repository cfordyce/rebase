/******************************************************************************
 *
 * File: cda.c
 *
 * Description: Source file for Project 1 functions
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 16-Jan-2001  Charles Fordyce     1.2
 *****************************************************************************/

/*****************************************************************************
 * includes
 *****************************************************************************/

#include <cdap.h>

/***************************************************************************

/*****************************************************************************
 * Methods
 *****************************************************************************/

void * CDA_malloc(size_t size)
{
  void * mem = malloc(size);

  if (mem == NULL)
    abort();

  return mem;
}


void * CDA_calloc(int num, size_t size)
{
  void * mem = calloc(num, size);

  if (mem == NULL && num > 0 && size > 0)
    abort();

  return mem;
}


void * CDA_realloc(void * old_ptr, size_t size)
{
  void * mem = realloc(old_ptr, size);

  if (mem == NULL && size > 0)
    abort();
  
  return mem;
}



void CDA_free(void * mem)
{
  if(mem != NULL)
    free(mem);
}

