/* input/output functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "b2w.h"

extern char dat[];
extern char morn[];
extern char midd[];
extern char even[];

int choice() {
  char s[3];
  int c, i;
  i = 0;
  while (i < 2 && (c = getchar()))
    s[i++] = c;
  ungetch(c); /* remove newline character */
  s[i] = '\0';
  return *s;
}


void collectData(FILE *fp) {
  float sum;
  int sumInt;
  
  printf("Enter your Bike to Work kilometres here\n");
    do {
      sum = 0;
      do {
        printf("\tDate:        ");
        while ((getLine(dat, MAXLINE)) != '\n')
          ;
      } while (strlen(dat) != DATW);

      do {
        printf("\tkm Morning:  ");
        while ((getLine(morn, MAXLINE)) != '\n')
          ;
      } while (strlen(morn) > KMW);
      sum += atof(morn);

      do {
        printf("\tkm Midday:   ");
        while ((getLine(midd, MAXLINE)) != '\n')
          ;
      } while (strlen(midd) > KMW);
      sum += atof(midd);

      do {
        printf("\tkm Evening:  ");
        while ((getLine(even, MAXLINE)) != '\n')
          ;
      } while (strlen(even) > KMW);
      sum += atof(even);
      sumInt = round2int(sum);

    fprintf(fp, FORMWRITE, dat, morn, midd, even, sumInt);

    printf("Enter another Bike to Work day (y/n)?\n");

  } while (choice() == 'y');
}


/* based on Kernighan & Ritchie, 1978 */
int getLine(char s[], int lim) {
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != '\n')
    s[i++] = c;
  s[i] = '\0';

  return c;
}


/* based on www.geeksforgeeks.org, 2025 */
int listDirTxt(char * path) {

  struct dirent *de;

  DIR *dr = opendir(path);

  if (dr == NULL) {
    printf("Could not open current directory ");
    exit(1);
  }

  while ((de = readdir(dr)) != NULL)
    if (strstr(de->d_name, ".txt") != NULL)
      printf("\t%s\n", de->d_name);

  closedir(dr);
  return 0;
}


void readTab(FILE *fp, char * tabname) {
  char buffer[MAXLINE];
  int i, j;
  int dat;
  float sum;
  int sumInt;
  int total;
  char day[3];
  char month[3];
  char year[5];

  rep(40, '-');
  printf("Content of %s\n", tabname);
  rep(40, '-');
  printf("Date        Morning Midday Evening   Sum\n");
  
  total = 0;

  while (fgets(buffer, MAXLINE, fp)) {
    sum = 0;

    /* collecting data from input line */
    for (i = BEGYEAR; i <= ENDYEAR; i++)
      year[i] = buffer[i];
    year[4] = '\0';

    for (i = BEGMONTH, j = 0; i <= ENDMONTH; i++)
      month[j++] = buffer[i];
    month[j] = '\0';

    for (i = BEGDAY, j = 0; i <= ENDDAY; i++)
      day[j++] = buffer[i];
    day[j] = '\0';

    for (i = BEGMORN, j = 0; i <= ENDMORN; i++)
      morn[j++] = buffer[i];
    morn[j] = '\0';
    sum += atof(morn);

    for (i = BEGMIDD, j = 0; i <= ENDMIDD; i++)
      midd[j++] = buffer[i];
    midd[j] = '\0';
    sum += atof(midd);
    
    for (i = BEGEVEN, j = 0; i <= ENDEVEN; i++)
      even[j++] = buffer[i];
    even[j] = '\0';
    sum += atof(even);
    sumInt = round2int(sum);

    printf(FORMPRINT, day, month, year, atof(morn), atof(midd), atof(even), sumInt);
    total += sumInt;
  }					      
  rep(40, '-');
  printf("Total: %d km\n", total);
  rep(40, '-');
  
}
