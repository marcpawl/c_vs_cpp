
#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void 
str_replace(std::string& target, const char needle, const char replacement)
{
  std::string::size_type n;
  while ( ( n = target.find( needle) ) != std::string::npos )
  {
    target[n] = replacement;
  }
}



int main(int argc, char** argv)
{
  std::string orig=
 #include "data.txt"

  const char needle=',';
  const char replacement = '\n';

  str_replace(orig, needle, replacement);

#if 0
  std::cout << orig;
#endif

  return 0;
} 

