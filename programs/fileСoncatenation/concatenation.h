#ifndef CPP
#define CPP

void play(int , char **);
struct arg
{
	char *fileout;
	char *equil;
	char *plas;
	char *file;
};
void init(int, char**);
void comparefileout(char *, arg* );
void compareEQUIL(char *, arg*);
void comparePLAS(char *, arg*);
void compareFILE(char *, arg*);
void ERROR();
char **separation(int , char **, char **);
char **del(int, char**);
void testexistence(int, char **);
int high(int, char **, char *, int);
char **memory(int, char **, char **, int , char *);
char **cpymemory(int, char **, char **, int, char *);
char **init_memory (int , char **, char **, char *);
void CPYmemory (char **, char **, int);
#endif