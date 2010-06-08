/**
 * My implementation of the Sieve of Eratosthenes
 */

#include <iostream>

#define SIZE 100
#define NOT 0

int main(void) {
  
  int nums[SIZE] = {NOT};

  for (int a=2; a < SIZE; ++a)
    nums[a] = a;
  
  for (int a=2; a < SIZE; ++a)    
    for (int b=a; b <= SIZE; ++b)
      if (a*b <= SIZE)
	nums[a*b] = NOT;

  for (int a=0; a < SIZE; ++a)
    if (NOT != nums[a])
      std::cout << nums[a] << "\n";
  
  return 0;
}

/**
   Output:
   2
   3
   5
   7
   11
   13
   17
   19
   23
   29
   31
   37
   41
   43
   47
   53
   59
   61
   67
   71
   73
   79
   83
   89
   97
*/
