/*******************************************************************
** File:     lab12.c
**
** Purpose:  Exercise from C programming class
**
**           This program uses a function atoint to convert a
**              character string containing only numeric characters.
**
** Related header files:   none
**
** Revision History:
**   3/30/90 - Original writing
*********************************************************************/

#include <stdio.h>
int getline(char n[], int j);
int atoint(char n[]);
#define MAX 25

int main(void)
{
        char in[MAX];

        printf("Enter an NUMERIC character string: ");
        getline(in, MAX);

        printf("Your String: %s has a numeric value: %d\n", in, atoint(in));

        return 0;

}


int getline(char line[], int length)
/*****************************************************
 * routine to get one line of input from keyboard.   *
 * Processing ends when limit is reached.            *
 *****************************************************/
{
        int charCount=0;
        char character;
        while (charCount<length-1           && 
                 ((character=getchar()) != EOF) &&
                   character != '\n')
        {
                line[charCount] = character;
                charCount = charCount  + 1;
        }
        line[charCount] = '\0';

        if (character == EOF)
                return -1;

        while (character != '\n') /* Dump the rest of the buffer */
                character=getchar();

        return charCount;
}

int atoint(char string[])
/*****************************************************
 * routine to translate an array of char, containing *
 * only decimal digits, into an integer and return   *
 * integer value.                                    *
 *****************************************************/
{
        int subscript=0, /* used to step through array */
                value,     /* contains accumulated value */
                sign;      /* stores initial sign (if present */

        sign = +1; /* the default is positive */

        /* check for leading sign '+' or '-'*/
        if (string[0] == '-')
        {
                sign = -1;
                subscript = 1; /* to skip over this character later on */
        }
        else
                if (string[0] == '+')
                {
                        sign = 1;
                        subscript = 1; /* to skip over this character later on */
                }

        value = 0;
        while (string[subscript] != '\0')
        {
                if (string[subscript] < '0' || string[subscript] > '9')
                        return(-1); /* invalid numeric in string! */
                else
                        value = value * 10 + (string[subscript] - '0');
                subscript = subscript + 1;
        }

        return (value * sign);
}

