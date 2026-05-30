/* miscellaneous functions */

#include <stdio.h>
#include <stdlib.h>
#include "b2w.h"

void printHeader(const char * vers, const char * vdat) {
  printf("\n");
  rep(30, '*');
  printf("     b2w %s, %s\n", vers, vdat);
  rep(30, '*');
  printf("\n");
}


void printMenu(char * menuItems){
  putchar('\n');	  
  rep(9, '*');  
  printf("Main menu\n");
  rep(9, '*');
  printf("%s", menuItems);
} 


void rep(int8 n, int8 c) {
  while (n-- > 0)
    putchar(c);
  putchar('\n');
}


int round2int(float f) {
  return f + 0.5;
}
