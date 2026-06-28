 /* symbolic constants */
#define MAXLINE   100       /* maximum input line size */
#define DATW        8       /* length of date field */
#define YEARW       4       /* length of year field */
#define MONTHW      2       /* length of month field */
#define DAYW        2       /* length of day field */
#define KMW         5       /* length of kilometre field */
#define BEGYEAR     0       /* character position where year begins */
#define BEGMONTH    4       /* character position where month begins */
#define BEGDAY      6       /* character position where day begins */
#define BEGMORN    11       /* character position where morning begins */
#define BEGMIDD    17       /* character position where midday begins */
#define BEGEVEN    23       /* character position where evening begins */

#define FORMWRITE  "%-10s,%-5s,%-5s,%-5s,%-5d\n"           /* format string for writing table */
#define FORMPRINT  "%-2s.%-2s.%-6s%7.1f %6.1f %7.1f %5d\n" /* format string for printing table */

/* typedefs */
/* check the size on your system and change it if necessary */
typedef unsigned char      int8;  /* 8bit integer */
typedef unsigned short int int16; /* 16bit integer */



/* general functions */
int choice();                                   /* fetch one character without newline */
void copy(char * s1, char * s2, int8 lim);      /* copy string up to the maximum length (lim) */
int getLine(char * s, int8 lim);                /* get next line */
void listDirFilt(char * filt);                  /* list files from the current directory which fits to the given filter */
void readTab(FILE *fp, char * tabname);         /* read table file and print information about it */
void rep(int8 n, int8 c);                       /* print n characters of type c */
int round2int(float f);                         /* round floating point to integer */

/* specific functions */
void collectData(FILE *fp);                             /* collect data from keyboard */
void printHeader(const char * vers, const char * vdat); /* print program name, version and date */
void printMenu(char * menuItems);                       /* print main menu */
