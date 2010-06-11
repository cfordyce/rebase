#include <iostream>

int main(void) {

  int size = 32;
  char str[size+1];
  str[size+1] = '\0';
  unsigned num = 346543;

  for (int c=0; c < size; c++)
    str[size-c] = 0 == (num >> c)%2 ? '0' : '1';

  std::cout << str << "\n";

  return 1;
}

// a >> b  means  a / (2*b)
// a << b  means  a * (2*b)
