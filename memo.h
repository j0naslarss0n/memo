// A header file to the memo program.
#ifndef __MYHEADER__
#define __MYHEADER__ 1
//struct tm tm =*localtime(&t);
//time_t t;

void initFunc(char * init);
void helpFunc();
void append(char * memo);
void search(char * search);
void print();
void delete(char * del);

#endif
