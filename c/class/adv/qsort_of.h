#ifndef QSORT_OF_H_INCLUDED
#define QSORT_OF_H_INCLUDED
/******************************************************************************
 *
 * Periodic Reporting System
 *
 * FILE: qsort_of.h
 * 
 * Description: The include file for qsort_of dependencies 
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 20-Nov-2000  Charles Fordyce     Original
 *****************************************************************************/
extern void qsort_of( void *objects, int num, int size,
                      int (*cmp)(const void *, const void *) );
#endif
