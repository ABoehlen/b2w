/* Program name: b2w
 * Author:       Adrian Boehlen
 *
 * The program is used to collect the kilometres for the campaign "Bike To Work"
 * in a comma-separated table
 * The fields are: Date, Morning, Midday, Evening and Sum
 * The value in "Sum" has to be entered in the appropriate field on the website biketowork.ch
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b2w.h"

/* global variable */
char tabname[MAXLINE]; /* table file name string */

int main(int argc, char * argv[]) {
  extern char tabname[];
  const char * vers = "v0.9";
  const char * vdat = "28.06.2026";
  int8 c;
  FILE *fp, *fopen();

  printHeader(vers, vdat);

  /* open table file */

  if (argc == 2) {
    printf("reading table %s...\n", argv[1]);
    strcpy(tabname, argv[1]);
  }
  else {
    printf("\ncsv-Files in current directory\n");
    rep(30, '-');
    listDirFilt(".csv");
    printf("\nChoose table or define a new one (for collecting only)\n");
    printf("Type 'quit' to terminate the program\n");
    printf("> ");
    while ((getLine(tabname, MAXLINE)) != '\n')
      ;
    if (strcmp(tabname, "quit") == 0) {
      printf("\n...terminating program...\n");
      return 0;
    }
  }

  /* main menu */
  char * menuItems = "\n\
    1  Collect data\n\
    2  List table content\n\
    3  Terminate program\n\n";
  
  do {
    printMenu(menuItems);
    c = choice();

    switch (c) {
      case '1':
        fp = fopen(tabname, "a");
        collectData(fp);
        fclose(fp);
        break;
      case '2':
        fp = fopen(tabname, "r");
        if (fp == NULL) {
          printf("no such file - terminating...\n");
          return 0;
        }
        readTab(fp, tabname);
        fclose(fp);
        break;
      case '3':
        break;
      default:
        printf("wrong input - terminating...\n");
        return 0;
    }
  } while (c != '3');

  printf("\n...terminating program...\n");

  return 0;
}
