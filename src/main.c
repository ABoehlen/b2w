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

extern char dat[];
extern char morn[];
extern char midd[];
extern char even[];
extern char tabname[];

int main() {
  char * vers = "v0.6";
  char * vdat =  "05.05.2026";
  int c;

  printHeader(vers, vdat);

  /* choose and open table file */
  FILE *fp, *fopen();

  printf("\ncsv-Files in current directory\n");
  rep(30, '-');
  listDirFilt(".", ".csv");
  printf("\nChoose table or define a new one (for collecting only): ");
  while ((getLine(tabname, MAXLINE)) != '\n')
    ;

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
