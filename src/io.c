/* input/output functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b2w.h"

static char dat[MAXLINE];  /* date string */
static char morn[MAXLINE]; /* kilometres morning string */
static char midd[MAXLINE]; /* kilometres midday string */
static char even[MAXLINE]; /* kilometres evening string */

int choice() {
  char s[3];
  int8 c, i;
  i = 0;
  while (i < 2 && (c = getchar()))
    s[i++] = c;
  s[i] = '\0';
  return *s;
}


void collectData(FILE *fp) {
  float sum;
  int16 sumInt;
  
  printf("Enter your 'Bike to Work' kilometres here\n");
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

    printf("Enter another 'Bike to Work' day (y/n)?\n");

  } while (choice() == 'y');
}


/* based on Kernighan & Ritchie, 1978 */
int getLine(char s[], int8 lim) {
  int8 c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != '\n')
    s[i++] = c;
  s[i] = '\0';

  return c;
}


/* we use popen() to list files in a directory on various operating systems, since C does not provide a built-in function fot this */
void listDirFilt(char * filt) {
  FILE *fp;
  char buf[MAXLINE];
  char cmd[MAXLINE];

  /* Command for Windows */
#ifdef _WIN32
  strcpy(cmd, "dir /B *");
  strcat(cmd, filt);
  fp = popen(cmd, "r");
#else
  /* Command for POSIX Systems */
  strcpy(cmd, "ls -1 *");
  strcat(cmd, filt);
  fp = popen(cmd, "r");
#endif

  /* check if the command was successful */
  if (fp == NULL) {
    printf("Error executing listDirFilt\n");
    return;
  }

  /* read every line and print it */
  while (fgets(buf, MAXLINE, fp) != NULL) {
    printf("%s", buf);
  }

  pclose(fp);
}


void readTab(FILE *fp, char * tabname) {
  char buffer[MAXLINE];
  int8 i, j;
  float sum;
  int16 sumInt;
  int16 total;
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

    /* divide the input line into the corresponding fields */
    for (i = BEGYEAR; i < BEGYEAR + YEARW; i++)
      year[i] = buffer[i];
    year[YEARW] = '\0';

    for (i = BEGMONTH, j = 0; i < BEGMONTH + MONTHW; i++)
      month[j++] = buffer[i];
    month[j] = '\0';

    for (i = BEGDAY, j = 0; i < BEGDAY + DAYW; i++)
      day[j++] = buffer[i];
    day[j] = '\0';

    for (i = BEGMORN, j = 0; i < BEGMORN + KMW; i++)
      morn[j++] = buffer[i];
    morn[j] = '\0';
    sum += atof(morn);

    for (i = BEGMIDD, j = 0; i < BEGMIDD + KMW; i++)
      midd[j++] = buffer[i];
    midd[j] = '\0';
    sum += atof(midd);
    
    for (i = BEGEVEN, j = 0; i < BEGEVEN + KMW; i++)
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
