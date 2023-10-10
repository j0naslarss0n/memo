#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "memo.h"
//#include "memo.c"

// -h

void helpFunc()

    {
    FILE *fp;
    int c;
    fp = fopen("help.md", "r");
    while(c !=EOF){
        printf("%c", c);
        c = fgetc(fp);
    }
    
    fclose(fp);
    
    }


// -i
void initFunc(char *init){

    FILE *fp;
    fp = fopen(init,"w+"); 
        
	fclose(fp);
}

    // -a
void append(char * memo){
    FILE *fp;
    time_t t;
    t = time(NULL);
    struct tm tm =*localtime(&t);

    //int id =1; 
    char c;
    fp = fopen("memo.csv", "r");
    char read[200];
    char ch[200];
    int i=0, id;
    char mess[200];

    if (fp == NULL){
        printf ("Error opening file");
    }
    // append message to the file.
    // fscanf to add ID to first column.
    
    //for (c =getc(fp); c != EOF; c =getc (fp))
        //if (c == '\n')
            //id = id+1;
    while( fgets(read, 200, fp) != NULL){}
            //fprintf(fp, "%d, ", id);
            //i = 1;
    sscanf(read, "%d,%s,%s", &i, ch, mess);     // ID-stamp
            id=++i;
	    //printf("%d\n", id);

        fp = fopen("memo.csv", "a+");
        //fprintf(fp, "%d,",id);
        fprintf(fp, "%d, %.2d-%.2d-%.2d %.2d:%.2d:%.2d,",id ,tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour,tm.tm_min, tm.tm_sec); // timestamp
        fprintf(fp, " \"%s\"\n", memo);        //message
    
    fclose(fp);
    
  }
  char search (char * search){
    FILE *fp;
	int line = 1;
	int find = 0;
	char temp[500];
	

	if((fp = fopen("memo.csv", "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 500, fp) != NULL) {
		if((strstr(temp, search)) != NULL) {
			printf("%s\n", temp);
			find++;
		}
		line++;
	}

	if(find == 0) {
		printf("Nothing found.\n");
	}
	
	fclose(fp);
	
}
  // -p
  char print(){
  
    FILE *fp;
    int c;
    fp = fopen("memo.csv", "r");
    while(c !=EOF){
        printf("%c", c);
        c = fgetc(fp);
    }
    
    fclose(fp);
   
}

// -d 

void delete(char * del){
    FILE *fp, *tmpfp;
    char read[200];
    char* endPtr;
    int d = strtol(del, &endPtr, 10);
    fp = fopen("memo.csv", "r");
    tmpfp =fopen("__temp__", "w+");
    if (fp == NULL || tmpfp == NULL){
        printf("error opening file(s)\n");
    }
    while(fgets(read, 200, fp) != NULL){
        int i;
        sscanf(read, "%d,", &i);
        if (d != i){    
            fputs(read, tmpfp);
            }  else {
            printf("Deleted: %s ", read);
        }
    }
    fclose(fp);
    fclose(tmpfp);

    remove("memo.csv");
    rename("__temp__", "memo.csv");

    

}
