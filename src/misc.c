/* miscellaneous functions */

#include <stdio.h>
#include <stdlib.h>
#include "b2w.h"

/* by Kernighan & Ritchie, 1978 */
void copy(char * s1, char * s2, int lim) {
  int i = 0;
  
  while ((s2[i] = s1[i]) != '\0') {
    ++i;
    if (i == lim-1) {
      s2[++i] = '\0';
      break;
    }
  }
}


void printHeader(char * vers, char * vdat) {
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


void rep(int n, int c) {
  while (n-- > 0)
    putchar(c);
  putchar('\n');
}


int round2int(float f) {
  return (int) (f + 0.5);
}
