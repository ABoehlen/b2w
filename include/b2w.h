#define MAXLINE   100       /* maximum input line size */
#define DATW        8       /* length of date field */
#define KMW         5       /* length of kilometer field */
#define BEGYEAR     0       /* character position where year begins */
#define ENDYEAR     3       /* character position where year ends */
#define BEGMONTH    4       /* character position where month begins */
#define ENDMONTH    5       /* character position where month ends */
#define BEGDAY      6       /* character position where day begins */
#define ENDDAY      7       /* character position where day ends */
#define BEGMORN    11       /* character position where morning begins */
#define ENDMORN    14       /* character position where morning ends */
#define BEGMIDD    16       /* character position where midday begins */
#define ENDMIDD    19       /* character position where midday ends */
#define BEGEVEN    21       /* character position where evening begins */
#define ENDEVEN    24       /* character position where evening ends */
#define BEGSUM     26       /* character position where sum begins */
#define ENDSUM     29       /* character position where sum ends */

#define FORMWRITE  "%-10s,%-4s,%-4s,%-4s,%-4d\n"           /* format string for writing table */
#define FORMPRINT  "%-2s.%-2s.%-6s%7.1f %6.1f %7.1f %5d\n" /* format string for printing table */

/* global variables */
char dat[MAXLINE];     /* date string */
char tabname[MAXLINE]; /* table file name string */
char morn[MAXLINE];    /* kilometres morning string */
char midd[MAXLINE];    /* kilometres midday string */
char even[MAXLINE];    /* kilometres evening string */

/* general functions */
int choice();                                   /* fetch one character without newline */
void copy(char * s1, char * s2, int lim);       /* copy string up to the maximum length (lim) */
int getLine(char * s, int lim);                 /* get next line */
int listDirFilt(char * path, char * filt);      /* list files from the given directory which fits to the given filter */
void readTab(FILE *fp, char * tabname);         /* read table file and print information about it */
void rep(int n, int c);                         /* print n characters of type c */
int round2int(float f);                         /* round floating point to integer */

/* specific functions */
void collectData(FILE *fp);                     /* collect data from keyboard */
void printHeader(char * vers, char * vdat);     /* print program name, version and date */
void printMenu(char * menuItems);               /* print main menu */
